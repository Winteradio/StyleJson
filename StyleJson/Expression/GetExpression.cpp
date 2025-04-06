#include "Expression/GetExpression.h"
#include "Expression/ExpressionFactory.h"

namespace StyleJson
{
	GetExpression::GetExpression()
		: m_Key()
		, m_Value()
	{}

	GetExpression::~GetExpression()
	{}

	bool GetExpression::Deserialize(const rapidjson::Value& _rawExpression)
	{
		if (_rawExpression.IsArray() && _rawExpression.Size() > 1)
		{
			const auto& rawKey = _rawExpression[0];
			const auto& rawValue = _rawExpression[1];

			if (rawKey.IsString() && rawValue.IsString())
			{
				m_Key.Set<std::string>(rawKey.GetString());
				m_Value.Set<std::string>(rawValue.GetString());

				return true;
			}
		}
		
		return false;
	}

	Expression::Value GetExpression::Evaluate(const PropertyFeatureMap& _featureMap)
	{

		return Expression::Value();
	}
}