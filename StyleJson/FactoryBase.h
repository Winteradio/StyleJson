#ifndef __STYLEJSON_FACTORY_H__
#define __STYLEJSON_FACTORY_H__

#include <memory>
#include <Rapidjson/rapidjson/document.h>

namespace StyleJson
{
	template<typename T>
	class FactoryBase
	{
		public :
			FactoryBase() {};
			virtual ~FactoryBase() {};

		public :
			virtual std::shared_ptr<T> Create(const rapidjson::Value& _jsonValue) = 0;
	};
};

#endif // __STYLEJSON_FACTORY_H__