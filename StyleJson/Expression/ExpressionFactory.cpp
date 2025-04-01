#include "Expression/ExpressionFactory.h"

#include "Enum.h"
#include "Expression/Expression.h"

namespace StyleJson
{
	ExpressionFactory& ExpressionFactory::GetInstance()
	{
		static ExpressionFactory instance;
		return instance;
	}

	std::shared_ptr<Expression> ExpressionFactory::Create(const rapidjson::Value& _jsonExpression)
	{
		return nullptr;
	}
}