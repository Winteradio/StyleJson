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

		public :
			bool Deserialize(const rapidjson::Value& _rawExpressionValue) override;
			const Data& GetData() const;

		private :
			Data m_data;
	};
};

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