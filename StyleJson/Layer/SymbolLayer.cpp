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

	bool SymbolLayer::DeserializeSub(const rapidjson::Value& _rawLayer)
	{
		return false;
	}
}