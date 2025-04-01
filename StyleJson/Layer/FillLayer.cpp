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

	bool FillLayer::Deserialize(const rapidjson::Value& _jsonLayer)
	{
		return false;
	}
}