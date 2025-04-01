#include "Parser.h"

#include "Style.h"

#include <LogProject/Log.h>

#include <RapidJson/rapidjson/document.h>
#include <RapidJson/rapidjson/istreamwrapper.h>

#include <RapidJson/rapidjson/writer.h>
#include <RapidJson/rapidjson/stringbuffer.h>

#include <fstream>
#include <iostream>

namespace StyleJson
{
	namespace Parser
	{
		std::shared_ptr<Style> Load(const std::string& filePath)
		{
			std::shared_ptr<std::ifstream> spFileStream = std::make_shared<std::ifstream>(filePath, std::ios::binary);

			if (!spFileStream->is_open())
			{
				LOGERROR() << "File Open Failed : " << filePath;
				return nullptr;
			}

			rapidjson::IStreamWrapper isw(*spFileStream);
			rapidjson::Document document;
			document.ParseStream(isw);
			if (document.HasParseError())
			{
				LOGERROR() << "Parse Error : " << document.GetParseError() << " Offset : " << document.GetErrorOffset();
				return nullptr;
			}

			std::shared_ptr<Style> spStyle = std::make_shared<Style>();
			if (spStyle->Deserialize(document))
			{
				LOGINFO() << "Successed to load style : " << filePath;
			}

			return spStyle;
		}
	}
}