#ifndef __STYLEJSON_PROPERTYFEATUREMAP_H__
#define __STYLEJSON_PROPERTYFEATUREMAP_H__

#include <unordered_map>
#include <string>

#include "Variant/Variant.h"

namespace StyleJson
{
	using PropertyFeature = wtr::Variant<bool, int, float, double, std::string>;

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
				m_propertyFeatureMap[_name].Set<T>(_property);
			}

			template<typename T>
			const T& Get(const std::string& _name) const
			{
				return m_propertyFeatureMap.at(_name).Get<T>();
			}

		private :
			std::unordered_map<std::string, PropertyFeature> m_propertyFeatureMap;
	};
};

#endif // __STYLEJSON_PROPERTYFEATUREMAP_H__