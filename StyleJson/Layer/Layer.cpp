#include "Layer/Layer.h"

#include "Enum.h"

namespace StyleJson
{
	Layer::Layer()
		: m_strID("")
		, m_strSourceID("")
		, m_strSourceLayer("")
		, m_nMinZoom(0)
		, m_nMaxZoom(0)
		, m_spFilter(nullptr)
	{}

	Layer::~Layer()
	{}

	const Enum::Layer::eType Layer::GetType()
	{
		return Enum::Layer::eType::eType_None;
	}

	const std::string& Layer::GetID() const
	{
		return m_strID;
	}

	const std::string& Layer::GetSourceID() const
	{
		return m_strSourceID;
	}

	const std::string& Layer::GetSourceLayer() const
	{
		return m_strSourceLayer;
	}

	const std::shared_ptr<Filter> Layer::GetFilter() const
	{
		return m_spFilter;
	}

	void Layer::SetID(const std::string& _layerID)
	{
		m_strID = _layerID;
	}

	void Layer::SetSourceID(const std::string& _sourceID)
	{
		m_strSourceID = _sourceID;
	}

	void Layer::SetSourceLayer(const std::string& _sourceLayer)
	{
		m_strSourceLayer = _sourceLayer;
	}

	void Layer::SetMinZoom(const int _minZoom)
	{
		m_nMinZoom = _minZoom;
	}

	void Layer::SetMaxZoom(const int _maxZoom)
	{
		m_nMaxZoom = _maxZoom;
	}

	bool Layer::Deserialize(const rapidjson::Value& _rawLayer)
	{
		if (!DeserializeBase(_rawLayer))
		{
			return false;
		}

		if (!DeserializeSub(_rawLayer))
		{
			return false;
		}

		return true;
	}

	bool Layer::DeserializeBase(const rapidjson::Value& _rawLayer)
	{
		for (const auto& enumPair : Enum::Layer::PROPERTY_LIST)
		{
			if (_rawLayer.HasMember(enumPair.strType))
			{
				if (Enum::Layer::eProperty::eProperty_Id == enumPair.eType)
				{
					SetID(_rawLayer[enumPair.strType].GetString());
				}
				else if (Enum::Layer::eProperty::eProperty_Source == enumPair.eType)
				{
					SetSourceID(_rawLayer[enumPair.strType].GetString());
				}
				else if (Enum::Layer::eProperty::eProperty_Source_Layer == enumPair.eType)
				{
					SetSourceLayer(_rawLayer[enumPair.strType].GetString());
				}
				else if (Enum::Layer::eProperty::eProperty_Min_Zoom == enumPair.eType)
				{
					SetMinZoom(_rawLayer[enumPair.strType].GetInt());
				}
				else if (Enum::Layer::eProperty::eProperty_Max_Zoom == enumPair.eType)
				{
					SetMaxZoom(_rawLayer[enumPair.strType].GetInt());
				}
				else if (Enum::Layer::eProperty::eProperty_Filter == enumPair.eType)
				{
					std::shared_ptr<Filter> spFilter = std::make_shared<Filter>();
					if (spFilter->Deserialize(_rawLayer[enumPair.strType]))
					{
						m_spFilter = spFilter;
					}
					else
					{
						return false;
					}
				}
				else
				{
					// TODO
				}
			}
		}

		return true;
	}
}