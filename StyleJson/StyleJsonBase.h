#ifndef __STYLEJSON_BASE_H__
#define __STYLEJSON_BASE_H__

#include <Rapidjson/rapidjson/document.h>

namespace StyleJson
{
	class Base
	{
		public :
			Base() {};
			virtual ~Base() {};

		public :
			virtual rapidjson::Value Serialize() = 0;
			virtual bool Deserialize(const rapidjson::Value& _jsonValue) = 0;
	};
};

#endif // __STYLEJSON_BASE_H__