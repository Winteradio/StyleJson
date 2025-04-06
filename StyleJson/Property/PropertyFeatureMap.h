#ifndef __STYLEJSON_PROPERTYFEATUREMAP_H__
#define __STYLEJSON_PROPERTYFEATUREMAP_H__

#include "Expression/ExpressionValue.h"
#include <unordered_map>


namespace StyleJson
{
	class PropertyFeatureMap
	{
		public :
			PropertyFeatureMap() = default;
			PropertyFeatureMap(const PropertyFeatureMap&) = default;
			PropertyFeatureMap(PropertyFeatureMap&&) = default;
			virtual ~PropertyFeatureMap() = default;

		public :
			template<typename T>
			void Add(const std::string& _name, const T& _property)
			{
				auto itr = m_propertyFeatureMap.find(_name);
				if (itr != m_propertyFeatureMap.end())
				{
					ExpressionValue expressionValue;
					expressionValue.Set<T>(_property);
				}
				else
				{
					itr->second.GetData().Set<T>(_property);
				}
			}

			const ExpressionValue& Get(const std::string& _name) const
			{
				const auto itr = m_propertyFeatureMap.find(_name);
				if (itr != m_propertyFeatureMap.end())
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
			std::unordered_map<std::string, ExpressionValue> m_propertyFeatureMap;
	};
};

#endif // __STYLEJSON_PROPERTYFEATUREMAP_H__