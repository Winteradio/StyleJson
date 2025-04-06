#ifndef __STYLEJSON_EXPRESSIONVALUE_H__
#define __STYLEJSON_EXPRESSIONVALUE_H__

#include "Variant/Variant.h"
#include "Base.h"

#include <string>
#include <vector>

namespace StyleJson
{
	class ExpressionValue : public Base
	{
		public :
			using Data = wtr::Variant<bool, int64_t, uint64_t, float, double, std::string, std::vector<ExpressionValue>>;

		public :
			ExpressionValue();
			~ExpressionValue();

			bool operator==(const ExpressionValue& _other) const;
			bool operator==(ExpressionValue&& _other) const;

		public :
			bool Deserialize(const rapidjson::Value& _rawExpressionValue) override;
			const Data& GetData() const;
			Data& GetData();

			const bool IsValid() const;

		private :
			Data m_data;
			bool m_valid;
	};
};

#include <iostream>
namespace std
{
	template<>
	struct hash<StyleJson::ExpressionValue>
	{
		size_t operator()(const StyleJson::ExpressionValue& _value) const
		{
			return _value.GetData().GetHash();
		}
	};
};


#endif // __STYLEJSON_EXPRESSIONVALUE_H__