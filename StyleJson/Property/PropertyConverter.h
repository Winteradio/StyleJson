#ifndef __STYLEJSON_PROPERTYCONVERTER_H__
#define __STYLEJSON_PROPERTYCONVERTER_H__

#include "Expression/Expression.h"
#include "Property/PropertyType.h"

namespace StyleJson
{
	template<typename T>
	struct PropertyConverter
	{
		static T FromExpressionValue(const Expression::Value& _value)
		{
			return T();
		}
	};

	template<>
	struct PropertyConverter<Color>
	{
		static Color FromExpressionValue(const Expression::Value& _value)
		{
			if (_value.Is<std::string>())
			{

			}

			return Color();
		}
	};
};

#endif // __STYLEJSON_PROPERTYCONVERTER_H__