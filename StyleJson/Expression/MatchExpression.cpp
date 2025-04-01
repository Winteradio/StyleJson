#include "Expression/MatchExpression.h"
#include "Expression/ExpressionFactory.h"

namespace StyleJson
{
	MatchExpression::MatchExpression()
	{}

	MatchExpression::~MatchExpression()
	{}

	bool MatchExpression::Deserialize(const rapidjson::Value& _jsonValue)
	{
		return false;
	}

	Expression::Value MatchExpression::Evaluate(const PropertyMap& _propertyMap)
	{
		if (m_Value.Is<Expression::ExpressionList>())
		{
			
		}

		return Expression::Value();
	}
}