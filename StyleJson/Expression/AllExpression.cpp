#include "Expression/AllExpression.h"
#include "Expression/ExpressionFactory.h"

namespace StyleJson
{
	AllExpression::AllExpression()
	{}

	AllExpression::~AllExpression()
	{}

	bool AllExpression::Deserialize(const rapidjson::Value& _rawExpression)
	{
		ExpressionList expressionList;

		if (_rawExpression.IsArray() && _rawExpression.Size() > 0)
		{
			expressionList.reserve(_rawExpression.Size()-1);

			for (const auto& rawValue : _rawExpression.GetArray())
			{
				std::shared_ptr<Expression> spExpression = ExpressionFactory::GetInstance().Create(rawValue);
				if (spExpression && spExpression->Deserialize(rawValue))
				{
					expressionList.push_back(spExpression);
				}
			}
		}

		if (expressionList.empty())
		{
			return false;
		}
		else 
		{
			m_expressionList = std::move(expressionList);
			return true;
		}
	}

	Expression::Value AllExpression::Evaluate(const PropertyFeatureMap& _featureMap)
	{

		return Expression::Value();
	}
}