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

	bool SymbolLayer::DeserializePaint(const rapidjson::Value& _rawPaint)
	{
		return true;
	}

	bool SymbolLayer::DeserializeLayout(const rapidjson::Value& _rawLayout)
	{
		return true;
	}
}