#include "Expression/GetExpression.h"
#include "Expression/ExpressionFactory.h"

namespace StyleJson
{
	GetExpression::GetExpression()
	{}

	GetExpression::~GetExpression()
	{}

	bool GetExpression::Deserialize(const rapidjson::Value& _jsonValue)
	{
		return false;
	}

	Expression::Value GetExpression::Evaluate(const PropertyMap& _propertyMap)
	{
		if (m_Value.Is<Expression::ExpressionList>())
		{
			
		}

		return Expression::Value();
	}
}