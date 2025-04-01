#ifndef __STYLEJSON_BASE_H__
#define __STYLEJSON_BASE_H__

#include <Rapidjson/rapidjson/document.h>

namespace StyleJson
{
	class Undefined {};

	class Base
	{
		public :
			Base() {};
			virtual ~Base() {};

		public :
			virtual bool Deserialize(const rapidjson::Value& _jsonValue) = 0;
	};
};

#endif // __STYLEJSON_BASE_H__