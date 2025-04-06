#include "Filter/Filter.h"

#include "Expression/Expression.h"
#include "Expression/ExpressionValue.h"
#include "Expression/ExpressionFactory.h"
#include "Expression/ExpressionFeatureMap.h"

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

	bool Filter::Check(const ExpressionFeatureMap& _featureMap)
	{
		if (!m_spExpression)
		{
			return false;
		}

		const auto expValue = m_spExpression->Evaluate(_featureMap);
		if (expValue.GetData().Is<bool>())
		{
			return expValue.GetData().Get<bool>();
		}
		else
		{
			return false;
		}
	}
}