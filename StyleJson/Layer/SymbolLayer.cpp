#include "Layer/SymbolLayer.h"

#include "Enum.h"

namespace StyleJson
{
	SymbolLayer::SymbolLayer()
	{}

	SymbolLayer::~SymbolLayer()
	{}

	const Enum::Layer::eType SymbolLayer::GetType()
	{
		return Enum::Layer::eType::eType_Symbol;
	}

	bool SymbolLayer::Deserialize(const rapidjson::Value& _jsonLayer)
	{
		return false;
	}
}