#ifndef __STYLEJSON_PROPERTYVALUE_H__
#define __STYLEJSON_PROPERTYVALUE_H__

#include "Base.h"
#include "Expression/Expression.h"
#include "Property/PropertyConverter.h"

namespace StyleJson
{
	template<typename T>
	class PropertyValue
	{
		using Value = wtr::Variant<Undefined, T, std::shared_ptr<Expression>>;

		public :
			PropertyValue() = delete;
			PropertyValue(const T& _constant)
				: m_Value(_constant)
			{}

			PropertyValue(const std::shared_ptr<Expression>& _expression)
				: m_Value(_expression)
			{}

			virtual ~PropertyValue() {};

		public :
			bool IsUndefined()
			{
				return m_Value.Is<Undefined>;
			}

			bool IsConstant()
			{
				return m_Value.Is<T>;
			}

			bool IsExpression()
			{
				return m_Value.Is<Expression>;
			}

		public :
			const T& GetConstant()
			{
				return m_Value.Get<T>();
			}

			const T& Evaluate(const ExpressionFeatureMap& _ExpressionFeatureMap)
			{
				const auto expValue = m_Value.Get<Expression>().Evaluate(_ExpressionFeatureMap);

				return PropertyConverter<T>::FromExpressionValue(expValue);
			}

		private :
			Value m_Value;
	};
};

#endif // __STYLEJSON_PROPERTYVALUE_H__