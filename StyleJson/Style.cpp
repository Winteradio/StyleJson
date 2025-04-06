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
				switch(enumPair.eType)
				{
					case Enum::Root::eProperty::eProperty_Version:
					case Enum::Root::eProperty::eProperty_Style_Version:
					case Enum::Root::eProperty::eProperty_Center:
					case Enum::Root::eProperty::eProperty_Imports:
					case Enum::Root::eProperty::eProperty_Glyphs:
					case Enum::Root::eProperty::eProperty_Sources:
					{
						// TODO
						break;
					}


					case Enum::Root::eProperty::eProperty_Sprite:
					{
						std::shared_ptr<Sprite> spSprite = std::make_shared<Sprite>();
						if (spSprite->Deserialize(_rawStyle[enumPair.strType]))
						{
							AddSprite(spSprite);
						}
						break;
					}

					case Enum::Root::eProperty::eProperty_Layers:
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
						else
						{
							std::shared_ptr<Layer> spLayer = LayerFactory::GetInstance().Create(rawLayerList);
							if (spLayer && spLayer->Deserialize(rawLayerList))
							{
								AddLayer(spLayer);
							}
						}
						break;
					}

					default :
					{
						// Nothing
						break;
					}
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

	const std::shared_ptr<Layer> Style::GetLayer(const std::string& _layerID) const
	{
		for (const auto& layer : m_vLayers)
		{
			if (layer->GetID() == _layerID)
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
		if (_spLayer)
		{
			m_vLayers.push_back(_spLayer);
		}
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