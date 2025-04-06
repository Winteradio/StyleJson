#ifndef __STYLEJSON_GETEXPRESSION_H__
#define __STYLEJSON_GETEXPRESSION_H__

#include "Expression/Expression.h"
#include "Expression/ExpressionValue.h"

namespace StyleJson
{
	class GetExpression : public Expression
	{
		public :
			GetExpression();
			~GetExpression();
			
		public :
			bool Deserialize(const rapidjson::Value& _rawExpression) final;
			const ExpressionValue Evaluate(const ExpressionFeatureMap& _featureMap) final;

		private :
			std::string m_Key;
	};
};

#endif // __STYLEJSON_GETEXPRESSION_H__