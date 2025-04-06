#ifndef __STYLEJSON_EXPRESSIONFEATUREMAP_H__
#define __STYLEJSON_EXPRESSIONFEATUREMAP_H__

#include "Expression/ExpressionValue.h"
#include <unordered_map>


namespace StyleJson
{
	class ExpressionFeatureMap
	{
		public :
			ExpressionFeatureMap() = default;
			ExpressionFeatureMap(const ExpressionFeatureMap&) = default;
			ExpressionFeatureMap(ExpressionFeatureMap&&) = default;
			virtual ~ExpressionFeatureMap() = default;

		public :
			template<typename T>
			void Add(const std::string& _name, const T& _property)
			{
				auto itr = m_ExpressionFeatureMap.find(_name);
				if (itr != m_ExpressionFeatureMap.end())
				{
					itr->second.GetData().Set<T>(_property);
				}
				else
				{
					ExpressionValue expressionValue;
					expressionValue.GetData().Set<T>(_property);

					m_ExpressionFeatureMap[_name] = expressionValue;
				}
			}

			const ExpressionValue& Get(const std::string& _name) const
			{
				const auto itr = m_ExpressionFeatureMap.find(_name);
				if (itr != m_ExpressionFeatureMap.end())
				{
					return itr->second;
				}
				else
				{
					static ExpressionValue nullValue;
					return nullValue;
				}
			}

		private :
			std::unordered_map<std::string, ExpressionValue> m_ExpressionFeatureMap;
	};
};

#endif // __STYLEJSON_EXPRESSIONFEATUREMAP_H__