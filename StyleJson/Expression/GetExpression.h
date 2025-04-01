#ifndef __STYLEJSON_GETEXPRESSION_H__
#define __STYLEJSON_GETEXPRESSION_H__

#include "Expression/Expression.h"

namespace StyleJson
{
	class GetExpression : public Expression
	{
		public :
			GetExpression();
			~GetExpression();
			
		public :
			bool Deserialize(const rapidjson::Value& _jsonValue) final;
			Value Evaluate(const PropertyMap& _propertyMap) final;
	};
};

#endif // __STYLEJSON_GETEXPRESSION_H__