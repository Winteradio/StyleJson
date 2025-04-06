#ifndef __STYLEJSON_GETEXPRESSION_H__
#define __STYLEJSON_GETEXPRESSION_H__

#include "Expression/Expression.h"

namespace StyleJson
{
	class GetExpression : public Expression
	{
		public :
			GetExpression();
			~GetExpression();
			
		public :
			bool Deserialize(const rapidjson::Value& _rawExpression) final;
			Value Evaluate(const PropertyFeatureMap& _featureMap) final;

		private :
			Value m_Key;
			Value m_Value;
	};
};

#endif // __STYLEJSON_GETEXPRESSION_H__