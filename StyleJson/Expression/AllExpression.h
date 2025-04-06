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
			bool Deserialize(const rapidjson::Value& _rawExpression) final;
			Value Evaluate(const PropertyFeatureMap& _featureMap) final;

		private :
			using ExpressionList = std::vector<std::shared_ptr<Expression>>;

			ExpressionList m_expressionList;
	};
};

#endif // __STYLEJSON_ALLEXPRESSIONH__