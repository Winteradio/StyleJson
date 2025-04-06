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

	bool LineLayer::DeserializeSub(const rapidjson::Value& _rawLayer)
	{
		return false;
	}
}