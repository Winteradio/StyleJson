#ifndef __STYLEJSON_ALLEXPRESSION_H__
#define __STYLEJSON_ALLEXPRESSION_H__

#include "Expression/Expression.h"

namespace StyleJson
{
	class AllExpression : public Expression
	{
		public :
			AllExpression();
			~AllExpression();
			
		public :
			bool Deserialize(const rapidjson::Value& _jsonValue) final;
			Value Evaluate(const PropertyMap& _propertyMap) final;
	};
};

#endif // __STYLEJSON_ALLEXPRESSIONH__