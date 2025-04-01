#include "Filter/Filter.h"

#include "Expression/Expression.h"
#include "Expression/ExpressionFactory.h"

namespace StyleJson
{
	Filter::Filter()
	{}

	Filter::~Filter()
	{}

	bool Filter::Deserialize(const rapidjson::Value& _jsonFilter)
	{
		return false;
	}

	bool Filter::Check(const PropertyMap& _propertyMap)
	{
		if (!m_spExpression)
		{
			return false;
		}

		const auto expValue = m_spExpression->Evaluate(_propertyMap);
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