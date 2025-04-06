#ifndef __STYLEJSON_EXPRESSION_H__
#define __STYLEJSON_EXPRESSION_H__

#include "Variant/Variant.h"
#include "Base.h"

#include <string>
#include <vector>
#include <memory>

namespace StyleJson
{
	class PropertyFeatureMap;

	class Expression : public Base
	{
		public :
			struct Value;
			using ValueList = std::vector<Value>;
			using ValueBase = wtr::Variant<bool, int, float, double, std::string, ValueList>;

			struct Value : public ValueBase
			{
				using ValueBase::ValueBase;
			};

		public :
			Expression() {};
			virtual ~Expression() {};

		public :
			virtual bool Deserialize(const rapidjson::Value& _rawExpression) = 0;
			virtual Value Evaluate(const PropertyFeatureMap& _featureMap) = 0;
	};
};

namespace std
{
	template<>
	struct hash<StyleJson::Expression::Value>
	{
		size_t operator()(const StyleJson::Expression::Value& _value) const
		{
			return _value.GetHash();
		}
	};
};

#endif // __STYLEJSON_EXPRESSION_H__