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

	std::shared_ptr<Layer> LayerFactory::Create(const rapidjson::Value& _rawLayer)
	{
		const size_t typeIndex = static_cast<size_t>(Enum::Layer::eProperty::eProperty_Type);
		const char* strType = Enum::Layer::PROPERTY_LIST[typeIndex].strType;
		if (_rawLayer.HasMember(strType))
		{
			const auto& jsonType = _rawLayer[strType];
			if (!jsonType.IsString())
			{
				return nullptr;
			}

			const std::string strLayerType = jsonType.GetString();
			for (const auto& enumPair : Enum::Layer::TYPE_LIST)
			{
				if (strLayerType == std::string(enumPair.strType))
				{
					switch (enumPair.eType)
					{
						case Enum::Layer::eType::eType_Circle:
						case Enum::Layer::eType::eType_Heatmap:
						case Enum::Layer::eType::eType_FillExtrusion:
						case Enum::Layer::eType::eType_Raster:
						case Enum::Layer::eType::eType_RasterParticle:
						case Enum::Layer::eType::eType_Hillshade:
						case Enum::Layer::eType::eType_Model:
						case Enum::Layer::eType::eType_Background:
						case Enum::Layer::eType::eType_Sky:
						case Enum::Layer::eType::eType_Slot:
						case Enum::Layer::eType::eType_Clip:
						{
							// TODO
							return nullptr;
						}

						case Enum::Layer::eType::eType_Fill:
						{
							return std::make_shared<FillLayer>();
						}

						case Enum::Layer::eType::eType_Line:
						{
							return std::make_shared<LineLayer>();
						}

						case Enum::Layer::eType::eType_Symbol:
						{
							return std::make_shared<SymbolLayer>();
						}
						
						default :
						{
							// Nothing
							return nullptr;
						}
					}
				}
			}
		}

		return nullptr;
	}
}