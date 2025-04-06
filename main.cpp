#include <LogProject/Log.h>
#include <LogProject/LogPlatform.h>

#include "Parser.h"
#include "Style.h"
#include "Layer/Layer.h"
#include "Filter/Filter.h"
#include "Expression/ExpressionFeatureMap.h"

int MAIN()
{
	Log::Init(1024, Log::Enum::eMode_Print, Log::Enum::eLevel_Type | Log::Enum::eLevel_File);

	const auto spStyle = StyleJson::Parser::Load("./StyleJson/basic.json");
	if (!spStyle)
	{
		LOGERROR() << "Failed to load style";
	}

	const std::string layerId = "polygon_line";
	std::shared_ptr<StyleJson::Filter> spFilter;
	for (const auto& spLayer : spStyle->GetLayers())
	{
		if (spLayer->GetID() == layerId)
		{
			spFilter = spLayer->GetFilter();
			break;
		}
	}

	if (!spFilter)
	{
		LOGERROR() << "Failed to load filter";
	}

	StyleJson::ExpressionFeatureMap featureMap;
	featureMap.Add(std::string("kind"), std::string("0x7460"));
	LOGINFO() << "Filter Value(" << "0x7460" << ") | Result Value(" << spFilter->Check(featureMap) << ")";

	LOGINFO() << "Style loaded successfully";

	system("pause");

	return 0;
}