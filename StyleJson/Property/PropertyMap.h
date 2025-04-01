#ifndef __STYLEJSON_PROPERTYMAP_H__
#define __STYLEJSON_PROPERTYMAP_H__

#include <unordered_map>
#include <string>

#include "Variant/Variant.h"

namespace StyleJson
{
	using PropertyFeature = wtr::Variant<int, float, std::string, bool>;

	class PropertyMap
	{
		public :
			PropertyMap() = default;
			PropertyMap(const PropertyMap&) = default;
			PropertyMap(PropertyMap&&) = default;
			virtual ~PropertyMap() = default;

		public :
			template<typename T>
			void Add(const std::string& _name, const T& _property)
			{
				m_propertyMap[_name].Set<T>(_property);
			}

			template<typename T>
			const T& Get(const std::string& _name) const
			{
				return m_propertyMap.at(_name).Get<T>();
			}

		private :
			std::unordered_map<std::string, PropertyFeature> m_propertyMap;
	};
};

#endif // __STYLEJSON_PROPERTYMAP_H__