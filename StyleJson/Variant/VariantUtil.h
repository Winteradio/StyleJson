#ifndef __STYLEJSON_VARIANT_UTIL_H__
#define __STYLEJSON_VARIANT_UTIL_H__

#include <type_traits>

template<typename T, typename U>
struct IsSame
{
	static const bool Value = false;
};

template<typename T>
struct IsSame<T, T>
{
	static const bool Value = true;
};

template<typename... Args>
struct IsEmptyPack
{
	static const bool Value = false;
};

template<>
struct IsEmptyPack<>
{
	static const bool Value = true;
};

template<typename... Args>
struct SizeCalculator 
{
    static constexpr size_t value = 0;
};

template<typename T>
struct SizeCalculator<T>
{
    static constexpr size_t value = sizeof(T);
};

template<typename T, typename... Args>
struct SizeCalculator<T, Args...>
{
    static constexpr size_t value = sizeof(T) + SizeCalculator<Args...>::value;
};

template<typename... Args>
constexpr size_t SizeOf()
{
    return SizeCalculator<Args...>::value;
}

template<typename... Args>
struct AlignCalculator 
{
	static constexpr size_t value = 0;
};

template<typename T>
struct AlignCalculator<T>
{
	static constexpr size_t value = alignof(T);
};

template<typename T, typename... Args>
struct AlignCalculator<T, Args...>
{
	static constexpr size_t value = (alignof(T) > AlignCalculator<Args...>::value) ? alignof(T) : AlignCalculator<Args...>::value;
};

template<typename... Args>
constexpr size_t AlignOf() 
{
	return AlignCalculator<Args...>::value;
};

template<size_t Size, size_t Align>
struct AlignedStorage
{
	alignas(Align) char data[Size];
};

template<typename... Args>
struct IndexCalculator
{
	static constexpr bool found = false;
	static constexpr int value = -1;
};

template<typename T, typename U, typename... Args>
struct IndexCalculator<T, U, Args...>
{
	static constexpr bool found = IsSame<T, U>::Value || IndexCalculator<T, Args...>::found;
	static constexpr int value = (found) ? 1 + IndexCalculator<T, Args...>::value : -1;
};

template<typename T, typename... Args>
constexpr int IndexOf()
{
	return IndexCalculator<T, Args...>::value;
}

template<typename... Args>
struct TotalIndexCalculator
{
	static constexpr size_t value = 0;
};

template<typename T, typename... Args>
struct TotalIndexCalculator<T, Args...>
{
	static constexpr size_t value = 1 + TotalIndexCalculator<Args...>::value;
};

template<typename T, typename... Args>
constexpr size_t TotalIndex()
{
	return TotalIndexCalculator<T, Args...>::value;
}

template<size_t Index, typename... Args>
struct TypeList;

template<size_t Index, typename T, typename... Args>
struct TypeList<Index, T, Args...>
{
	using Type = typename TypeList<Index - 1, Args...>::Type;
};

template<typename T, typename... Args>
struct TypeList<0, T, Args...>
{
	using Type = T;
};

#endif // __STULEJSON_VARIANT_UTIL_H__