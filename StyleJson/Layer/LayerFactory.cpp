#include "Layer/LayerFactory.h"

#include "Enum.h"

#include "Layer/LineLayer.h"
#include "Layer/FillLayer.h"
#include "Layer/SymbolLayer.h"

#include <string>

namespace StyleJson
{
	LayerFactory& LayerFactory::GetInstance()
	{
		static LayerFactory instance;
		return instance;
	}

	std::shared_ptr<Layer> LayerFactory::Create(const rapidjson::Value& _jsonLayer)
	{
		const size_t propertyIndex = static_cast<size_t>(Enum::Layer::eProperty::eProperty_Type);
		const char* strProperty = Enum::Layer::PROPERTY_LIST[propertyIndex].strType;
		if (_jsonLayer.HasMember(strProperty))
		{
			const auto& jsonType = _jsonLayer[strProperty];
			if (!jsonType.IsString())
			{
				return nullptr;
			}

			const std::string strLayerType = jsonType.GetString();
			for (const auto& typePair : Enum::Layer::TYPE_LIST)
			{
				if (strLayerType == std::string(typePair.strType))
				{
					if (Enum::Layer::eType::eType_Line == typePair.eType)
					{
						return std::make_shared<LineLayer>();
					}
					else if (Enum::Layer::eType::eType_Fill == typePair.eType)
					{
						return std::make_shared<FillLayer>();
					}
					else if (Enum::Layer::eType::eType_Symbol == typePair.eType)
					{
						return std::make_shared<SymbolLayer>();
					}
					else
					{
						// TODO
						return nullptr;
					}
				}
			}
		}

		return nullptr;
	}
}