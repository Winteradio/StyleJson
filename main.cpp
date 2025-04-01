#include <LogProject/Log.h>
#include <LogProject/LogPlatform.h>

#include "Parser.h"

int MAIN()
{
	Log::Init(1024, Log::Enum::eMode_Print, Log::Enum::eLevel_Type | Log::Enum::eLevel_File);

	const auto spStyle = StyleJson::Parser::Load("./StyleJson/basic.json");
	if (spStyle == nullptr)
	{
		LOGERROR() << "Failed to load style";
	}

	LOGINFO() << "Style loaded successfully";

	system("pause");

	return 0;
}