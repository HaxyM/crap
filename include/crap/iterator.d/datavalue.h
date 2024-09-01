#ifndef CRAP_ITERATOR_DATAVALUE
#define CRAP_ITERATOR_DATAVALUE

#include <cstddef>

namespace crap
{
 template <class Type, Type...> struct dataValue;

 template <class Type> struct dataValue<Type>
 {
  constexpr static std :: nullptr_t data() noexcept;
 };

 template <class Type, Type ... Values> struct dataValue
 {
  constexpr const static Type value[sizeof...(Values)] = {Values...};
  constexpr const static Type (& data() noexcept)[sizeof...(Values)];
 };
}

template <class Type>
inline constexpr std :: nullptr_t crap :: dataValue <Type> :: data() noexcept
{
 return nullptr;
}

template <class Type, Type ... Values>
constexpr const Type crap :: dataValue <Type, Values...> :: value[sizeof...(Values)];

template <class Type, Type ... Values>
inline constexpr const Type (& crap :: dataValue <Type, Values...> :: data() noexcept)[sizeof...(Values)]
{
 return crap :: dataValue <Type, Values...> :: value;
}
#endif

