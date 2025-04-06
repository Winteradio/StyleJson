#ifndef __STYLEJSON_FILTER_H__
#define __STYLEJSON_FILTER_H__

#include <memory>
#include "Base.h"

namespace StyleJson
{
	class Expression;
	class ExpressionFeatureMap;

	class Filter : public Base
	{
		public :
			Filter();
			virtual ~Filter();

		public :
			bool Deserialize(const rapidjson::Value& _rawFilter) override;
			bool Check(const ExpressionFeatureMap& _featureMap);

		private :
			std::shared_ptr<Expression> m_spExpression;
	};
};

#endif // __STYLEJSON_FILTER_H__