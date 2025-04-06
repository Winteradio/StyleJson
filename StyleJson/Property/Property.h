#ifndef __STYLEJSON_PROPERTY_H__
#define __STYLEJSON_PROPERTY_H__

#include <tuple>

namespace StyleJson
{
	template<typename... Args>
	class Property
	{
		public :
			Property() = default;
			Property(const Args&... _args)
				: m_property(std::forward<_args>(...))
			{}
			Property(const Property&) = default;
			virtual ~Property() = default;

		public :
			template<typename T>
			const T& Get() const
			{
				return std::get<T>(m_property);
			}

			template<typename T>
			T& Get()
			{
				return std::get<T>(m_property);
			}

		private :
			std::tuple<Args...> m_property;
	};
};

#endif // __STYLEJSON_PROPERTY_H__