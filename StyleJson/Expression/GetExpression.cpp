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

			m_Key = (rawKey.IsString()) ? rawKey.GetString() : std::string("");

			ExpressionValue expValue;
			if (expValue.Deserialize(rawValue))
			{
				m_Value = std::move(expValue);
			}
		}

		if (m_Key.empty() || m_Value.GetData().GetIndex() == -1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	const ExpressionValue GetExpression::Evaluate(const PropertyFeatureMap& _featureMap)
	{
		
		return ExpressionValue();
	}
}