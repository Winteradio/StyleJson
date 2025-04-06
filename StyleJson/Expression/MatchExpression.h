#ifndef __STYLEJSON_MATCHEXPRESSION_H__
#define __STYLEJSON_MATCHEXPRESSION_H__

#include <unordered_set>

#include "Expression/Expression.h"
#include "Expression/ExpressionValue.h"

namespace StyleJson
{
	class MatchExpression : public Expression
	{
		public :
			MatchExpression();
			~MatchExpression();
			
		public :
			bool Deserialize(const rapidjson::Value& _rawExpression) final;
			const ExpressionValue Evaluate(const ExpressionFeatureMap& _featureMap) final;

		private :
			struct stMatchEntry
			{
				std::unordered_set<ExpressionValue> InputKeys;
				ExpressionValue OutputValue;

				stMatchEntry();
			};

			using MatchEntryList = std::vector<stMatchEntry>;

		private :
			std::shared_ptr<Expression> m_spInputExpression;
			MatchEntryList m_matchEntryList;
			ExpressionValue m_matchFallBack;
	};
};

#endif // __STYLEJSON_MATCHEXPRESSION_H__