#include "Expression/AllExpression.h"
#include "Expression/ExpressionFactory.h"

namespace StyleJson
{
	AllExpression::AllExpression()
	{}

	AllExpression::~AllExpression()
	{}

	bool AllExpression::Deserialize(const rapidjson::Value& _jsonValue)
	{
		return false;
	}

	Expression::Value AllExpression::Evaluate(const PropertyMap& _propertyMap)
	{
		if (m_Value.Is<Expression::ExpressionList>())
		{
			
		}

		return Expression::Value();
	}
}