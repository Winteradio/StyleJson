#ifndef __STYLEJSON_FILTER_H__
#define __STYLEJSON_FILTER_H__

#include <memory>
#include "Base.h"

namespace StyleJson
{
	class Expression;
	class PropertyMap;

	class Filter : public Base
	{
		public :
			Filter();
			virtual ~Filter();

		public :
			bool Deserialize(const rapidjson::Value& _jsonFilter) override;
			bool Check(const PropertyMap& _propertyMap);

		private :
			std::shared_ptr<Expression> m_spExpression;
	};
};

#endif // __STYLEJSON_FILTER_H__