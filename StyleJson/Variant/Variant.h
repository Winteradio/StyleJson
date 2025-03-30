#ifndef __STYLEJSON_VARIANT_H__
#define __STYLEJSON_VARIANT_H__

#include "Variant/VariantUtil.h"

namespace StyleJson
{	
	template<typename... Args>
	class Variant
	{
		private :
			static constexpr size_t g_MaxSize = SizeOf<Args...>();
			static constexpr size_t g_MaxAlign = AlignOf<Args...>();

			using Storage = AlignedStorage<g_MaxSize, g_MaxAlign>;

		public :
			Variant() 
				: m_nCurrentIndex(-1)
			{}

			virtual ~Variant()
			{}

			template<typename T>
			Variant(const T& _value)
			{
				Set(_value);
			}

			template<typename T>
			Variant(T&& _value)
			{
				Set(std::move(_value));
			}

			Variant& operator=(const Variant& _other)
			{
				if (this != &_other)
				{
					this->Destroy();
					this->m_tStorage = _other.m_tStorage;
					this->m_nCurrentIndex = _other.m_nCurrentIndex;
				}
				return *this;
			}

			Variant& operator=(Variant&& _other)
			{
				if (this != &_other)
				{
					this->Destroy();
					this->m_tStorage = std::move(_other.m_tStorage);
					this->m_nCurrentIndex = _other.m_nCurrentIndex;
				}
				return *this;
			}

		public:
			template<typename T>
			void Set(const T& _value)
			{
				constexpr int index = IndexOf<T, Args...>();
				if (index != -1)
				{
					Destroy();
					m_nCurrentIndex = index;
					new (&m_tStorage.data) T(_value);
				}
				else
				{
					assert(false && "Type not supported in Variant");
				}
			}

			template<typename T>
			void Set(T&& _value)
			{
				constexpr int index = IndexOf<T, Args...>();
				if (index != -1)
				{
					Destroy();
					m_nCurrentIndex = index;
					new (&m_tStorage.data) T(std::move(_value));
				}
				else
				{
					assert(false && "Type not supported in Variant");
				}
			}

			template<typename T>
			const T& Get() const
			{
				if (IndexOf<T, Args...>() == m_nCurrentIndex)
				{
					return *reinterpret_cast<const T*>(&m_tStorage.data);
				}
				else
				{
					assert(false && "Type not supported in Variant");

					static T emptyValue;
					return emptyValue;
				}
			}

			int GetIndex() const
			{
				return m_nCurrentIndex;
			}

			template<typename T>
			const bool Is() const
			{
				return IndexOf<T, Args...>() == m_nCurrentIndex;
			}

		private :
			void Destroy()
			{
				if (m_nCurrentIndex != -1)
				{
					DestroyMatcher<Args...>::Destroy(m_tStorage, m_nCurrentIndex);
				}
			}

			template<typename... Lists>
			struct DestroyMatcher
			{
				static void Destroy(Storage& _storage, const int _index) 
				{
					assert(false && "Type not supported in Variant");
				};
			};

			template<typename T, typename... Lists>
			struct DestroyMatcher<T, Lists... >
			{
				static void Destroy(Storage& _storage, const int _index)
				{
					if (_index == IndexOf<T, Args...>())
					{
						reinterpret_cast<T*>(&_storage.data)->~T();
					}
					else
					{
						DestroyMatcher<Lists...>::Destroy(_storage, _index);
					}
				}
			};

		private :
			int m_nCurrentIndex;
			Storage m_tStorage;
	};
};

#endif // __STYLEJSON_VARIANT_H__