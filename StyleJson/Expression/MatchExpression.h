#ifndef __STYLEJSON_MATCHEXPRESSION_H__
#define __STYLEJSON_MATCHEXPRESSION_H__

#include "Expression/Expression.h"

namespace StyleJson
{
	class MatchExpression : public Expression
	{
		public :
			MatchExpression();
			~MatchExpression();
			
		public :
			bool Deserialize(const rapidjson::Value& _jsonValue) final;
			Value Evaluate(const PropertyMap& _propertyMap) final;
	};
};

#endif // __STYLEJSON_MATCHEXPRESSION_H__