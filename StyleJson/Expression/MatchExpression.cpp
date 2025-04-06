#include "Expression/MatchExpression.h"
#include "Expression/ExpressionFactory.h"

namespace StyleJson
{
	MatchExpression::stMatchEntry::stMatchEntry()
		: InputKeys()
		, OutputValue()
	{}

	MatchExpression::MatchExpression()
		: m_spInputExpression(nullptr)
		, m_matchEntryList()
	{}

	MatchExpression::~MatchExpression()
	{}

	bool MatchExpression::Deserialize(const rapidjson::Value& _rawExpression)
	{
		/*
					for (const auto& rawValue : _rawExpression.GetArray())
			{
				std::shared_ptr<Expression> spExpression = ExpressionFactory::GetInstance().Create(rawValue);
				if (spExpression && spExpression->Deserialize(rawValue))
				{
					expressionList.push_back(spExpression);
				}
			}
		*/
		if (_rawExpression.IsArray() && _rawExpression.Size() > 1)
		{
			const auto& rawMatchValue = _rawExpression[1];
			{
				std::shared_ptr<Expression> spExpression = ExpressionFactory::GetInstance().Create(rawMatchValue);
				if (spExpression && spExpression->Deserialize(rawMatchValue))
				{
					m_spInputExpression = spExpression;
				}
				else
				{
					return false;
				}
			}

			rapidjson::SizeType index = 1;
			while (index < _rawExpression.Size())
			{
			}
		}

		return false;
	}

	Expression::Value MatchExpression::Evaluate(const PropertyFeatureMap& _featureMap)
	{
		return Expression::Value();
	}
}