#include "Expression/GetExpression.h"
#include "Expression/ExpressionFactory.h"
#include "Expression/ExpressionFeatureMap.h"

namespace StyleJson
{
	GetExpression::GetExpression()
		: m_Key()
	{}

	GetExpression::~GetExpression()
	{}

	bool GetExpression::Deserialize(const rapidjson::Value& _rawExpression)
	{
		if (_rawExpression.IsArray() && _rawExpression.Size() > 1)
		{
			const auto& rawKey = _rawExpression[1];

			m_Key = (rawKey.IsString()) ? rawKey.GetString() : std::string("");
		}

		if (m_Key.empty())
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	const ExpressionValue GetExpression::Evaluate(const ExpressionFeatureMap& _featureMap)
	{
		return _featureMap.Get(m_Key);
	}
}