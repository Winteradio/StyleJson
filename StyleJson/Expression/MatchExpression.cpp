#include "Expression/MatchExpression.h"
#include "Expression/ExpressionFactory.h"

#include <iostream>

namespace StyleJson
{
	MatchExpression::stMatchEntry::stMatchEntry()
		: InputKeys()
		, OutputValue()
	{}

	MatchExpression::MatchExpression()
		: m_spInputExpression(nullptr)
		, m_matchEntryList()
		, m_matchFallBack()
	{}

	MatchExpression::~MatchExpression()
	{}

	bool MatchExpression::Deserialize(const rapidjson::Value& _rawExpression)
	{
		if (_rawExpression.IsArray() && _rawExpression.Size() > 1)
		{
			rapidjson::SizeType index = 0;

			const rapidjson::SizeType matchIndex = ++index;
			const auto& rawMatchValue = _rawExpression[matchIndex];
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

			while (index < (_rawExpression.Size() - 2))
			{
				stMatchEntry matchEntry;

				const rapidjson::SizeType inputIndex = ++index;
				const auto& rawInputValue = _rawExpression[inputIndex];

				if (rawInputValue.IsArray())
				{
					for (const auto& rawInput : rawInputValue.GetArray())
					{
						ExpressionValue inputValue;
						if (inputValue.Deserialize(rawInput))
						{
							matchEntry.InputKeys.insert(inputValue);
						}
					}
				}

				const rapidjson::SizeType outputIndex = ++index;
				const auto& rawOutputValue = _rawExpression[outputIndex];

				ExpressionValue outputValue;
				if (outputValue.Deserialize(rawOutputValue))
				{
					matchEntry.OutputValue = std::move(outputValue);
				}

				m_matchEntryList.push_back(std::move(matchEntry));
			}

			if (m_matchEntryList.empty())
			{
				return false;
			}

			const rapidjson::SizeType fallBackIndex = ++index;
			const auto& rawMatchFallBack = _rawExpression[fallBackIndex];

			ExpressionValue fallBackValue;
			if (fallBackValue.Deserialize(rawMatchFallBack))
			{
				m_matchFallBack = std::move(fallBackValue);
			}
			else
			{
				return false;
			}
		}

		return true;
	}

	const ExpressionValue MatchExpression::Evaluate(const ExpressionFeatureMap& _featureMap)
	{
		ExpressionValue matchKey = (m_spInputExpression) ? m_spInputExpression->Evaluate(_featureMap) : ExpressionValue();

		for (const auto& matchEntry : m_matchEntryList)
		{
			const auto itr = matchEntry.InputKeys.find(matchKey);
			if (itr != matchEntry.InputKeys.end())
			{
				return matchEntry.OutputValue;
			}
		}

		return m_matchFallBack;
	}
}