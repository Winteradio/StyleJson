#ifndef __STYLEJSON_EXPRESSIONFACTORY_H__
#define __STYLEJSON_EXPRESSIONFACTORY_H__

#include <memory>
#include "FactoryBase.h"

namespace StyleJson
{
	class Expression;

	class ExpressionFactory : public FactoryBase<Expression>
	{
		private :
			ExpressionFactory() = default;
			~ExpressionFactory() = default;

		public :
			static ExpressionFactory& GetInstance();

		public :
			std::shared_ptr<Expression> Create(const rapidjson::Value& _rawExpression) override;
	};
};

#endif // __STYLEJSON_EXPRESSIONFACTORY_H__