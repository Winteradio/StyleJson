#ifndef __STYLEJSON_EXPRESSION_H__
#define __STYLEJSON_EXPRESSION_H__

#include "Variant/Variant.h"
#include "Base.h"
#include "Property/PropertyMap.h"

#include <string>
#include <vector>

namespace StyleJson
{
	class Expression : public Base
	{
		public :
			using ExpressionList = std::vector<Expression>;
			using Value = wtr::Variant<bool, int, float, double, std::string, ExpressionList>;

		public :
			Expression() {};
			virtual ~Expression() {};

		public :
			virtual bool Deserialize(const rapidjson::Value& _jsonValue) = 0;
			virtual Value Evaluate(const PropertyMap& _propertyMap) = 0;

		protected : 
		
			Value m_Value;
	};
};

#endif // __STYLEJSON_EXPRESSION_H__