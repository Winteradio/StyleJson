#include "Layer/FillLayer.h"

#include "Enum.h"

namespace StyleJson
{
	FillLayer::FillLayer()
	{}

	FillLayer::~FillLayer()
	{}

	const Enum::Layer::eType FillLayer::GetType()
	{
		return Enum::Layer::eType::eType_Fill;
	}

	bool FillLayer::DeserializePaint(const rapidjson::Value& _rawPaint)
	{
		return true;
	}

	bool FillLayer::DeserializeLayout(const rapidjson::Value& _rawLayout)
	{
		return true;
	}
}