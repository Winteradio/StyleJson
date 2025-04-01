#ifndef __STYLEJSON_PARSER_H__
#define __STYLEJSON_PARSER_H__

#include <string>
#include <memory>

namespace StyleJson
{
	class Style;

	namespace Parser
	{
		std::shared_ptr<Style> Load(const std::string& filePath);
	};
};

#endif // __STYLEJSON_PARSER_H__