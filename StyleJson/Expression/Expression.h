#ifndef __STYLEJSON_EXPRESSION_H__
#define __STYLEJSON_EXPRESSION_H__

#include "Variant/Variant.h"
#include "Base.h"

#include <string>
#include <vector>

namespace StyleJson
{
	class ExpressionFeatureMap;
	class ExpressionValue;

	class Expression : public Base
	{
		public :
			Expression() {};
			virtual ~Expression() {};

		public :
			virtual bool Deserialize(const rapidjson::Value& _rawExpression) = 0;
			virtual const ExpressionValue Evaluate(const ExpressionFeatureMap& _featureMap) = 0;
	};
};

#endif // __STYLEJSON_EXPRESSION_H__