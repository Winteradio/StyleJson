#include "Style.h"

#include "Enum.h"

#include "Layer/LayerFactory.h"
#include "Layer/Layer.h"
#include "Sprite/Sprite.h"

namespace StyleJson
{
	Style::Style()
	{}

	Style::~Style()
	{}

	bool Style::Deserialize(const rapidjson::Value& _rawStyle)
	{
		for (const auto& enumPair : Enum::Root::PROPERTY_LIST)
		{
			if (_rawStyle.HasMember(enumPair.strType))
			{
				if (Enum::Root::eProperty::eProperty_Layers == enumPair.eType)
				{
					const auto& rawLayerList = _rawStyle[enumPair.strType];
					if (rawLayerList.IsArray())
					{
						for (const auto& rawLayer : rawLayerList.GetArray())
						{
							std::shared_ptr<Layer> spLayer = LayerFactory::GetInstance().Create(rawLayer);
							if (spLayer && spLayer->Deserialize(rawLayer))
							{
								AddLayer(spLayer);
							}
						}
					}
				}
				else if (Enum::Root::eProperty::eProperty_Sprite == enumPair.eType)
				{
					std::shared_ptr<Sprite> spSprite = std::make_shared<Sprite>();
					if (spSprite->Deserialize(_rawStyle[enumPair.strType]))
					{
						AddSprite(spSprite);
					}
				}
				else
				{
					// TODO
				}
			}
		}

		if (m_vLayers.empty() && (!m_spSprite))
		{
			return false;
		}

		return true;
	}

	const std::shared_ptr<Sprite> Style::GetSprite() const
	{
		return m_spSprite;
	}

	const std::shared_ptr<Layer> Style::GetLayer(const std::string& _layer) const
	{
		for (const auto& layer : m_vLayers)
		{
			if (layer->GetID() == _layer)
			{
				return layer;
			}
		}
		return nullptr;
	}

	const std::vector<std::shared_ptr<Layer>> Style::GetLayers() const
	{
		return m_vLayers;
	}

	void Style::AddLayer(std::shared_ptr<Layer> _spLayer)
	{
		m_vLayers.push_back(_spLayer);
	}

	void Style::AddSprite(std::shared_ptr<Sprite> _spSprite)
	{
		if (m_spSprite)
		{
			m_spSprite.reset();
			m_spSprite = nullptr;
		}
	}
}