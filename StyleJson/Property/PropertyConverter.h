#ifndef __STYLEJSON_PROPERTYCONVERTER_H__
#define __STYLEJSON_PROPERTYCONVERTER_H__

#include "Expression/ExpressionValue.h"
#include "Property/PropertyType.h"

namespace StyleJson
{
	template<typename T>
	struct PropertyConverter
	{
		static T FromExpressionValue(const ExpressionValue& _value)
		{
			return _value.GetData().Get<T>();
		}
	};

	template<>
	struct PropertyConverter<Color>
	{
		static Color FromExpressionValue(const ExpressionValue& _value)
		{
			Color color;

			if (_value.GetData().Is<std::string>())
			{
				const auto& rawColor = _value.GetData().Get<std::string>();
			}

			return color;
		}
	};
};

#endif // __STYLEJSON_PROPERTYCONVERTER_H__