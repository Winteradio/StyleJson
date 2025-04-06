#include "Layer/LineLayer.h"

#include "Enum.h"

namespace StyleJson
{
	LineLayer::LineLayer()
	{}

	LineLayer::~LineLayer()
	{}

	const Enum::Layer::eType LineLayer::GetType()
	{
		return Enum::Layer::eType::eType_Line;
	}

	bool LineLayer::DeserializePaint(const rapidjson::Value& _rawPaint)
	{
		for (const auto& enumPair : Enum::Layer::SUB_PROPERTY_LIST)
		{

		}

		return true;
	}

	bool LineLayer::DeserializeLayout(const rapidjson::Value& _rawLayout)
	{
		for (const auto& enumPair : Enum::Layer::SUB_PROPERTY_LIST)
		{

		}

		return true;
	}
}