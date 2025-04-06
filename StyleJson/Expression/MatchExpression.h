#ifndef __STYLEJSON_MATCHEXPRESSION_H__
#define __STYLEJSON_MATCHEXPRESSION_H__

#include <unordered_set>

#include "Expression/Expression.h"

namespace StyleJson
{
	class MatchExpression : public Expression
	{
		public :
			MatchExpression();
			~MatchExpression();
			
		public :
			bool Deserialize(const rapidjson::Value& _rawExpression) final;
			Value Evaluate(const PropertyFeatureMap& _featureMap) final;

		private :
			struct stMatchEntry
			{
				std::unordered_set<Value> InputKeys;
				Value OutputValue;

				stMatchEntry();
			};

			using MatchEntryList = std::vector<stMatchEntry>;

		private :
			std::shared_ptr<Expression> m_spInputExpression;
			MatchEntryList m_matchEntryList;
	};
};

#endif // __STYLEJSON_MATCHEXPRESSION_H__