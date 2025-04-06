#include "Filter/Filter.h"

#include "Expression/Expression.h"
#include "Expression/ExpressionFactory.h"

namespace StyleJson
{
	Filter::Filter()
	{}

	Filter::~Filter()
	{}

	bool Filter::Deserialize(const rapidjson::Value& _rawFilter)
	{
		std::shared_ptr<Expression> spExpression = ExpressionFactory::GetInstance().Create(_rawFilter);
		if (spExpression && spExpression->Deserialize(_rawFilter))
		{
			m_spExpression = spExpression;
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Filter::Check(const PropertyFeatureMap& _featureMap)
	{
		if (!m_spExpression)
		{
			return false;
		}

		const auto expValue = m_spExpression->Evaluate(_featureMap);
		if (!expValue.Is<bool>())
		{
			return false;
		}
		else
		{
			return expValue.Get<bool>();
		}
	}
}