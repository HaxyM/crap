#ifndef CRAP_ITERATOR_DATATYPE
#define CRAP_ITERATOR_DATATYPE

#include <cstddef>

#include "datavalue.h"

namespace crap
{
 template <class ... Types> struct dataType;
 
 template <> struct dataType<>
 {
  constexpr static std :: nullptr_t data() noexcept;
 };

 template <class Type, Type ... Values> struct dataType<std :: integral_constant<Type, Values>...>
	 : dataValue<Type, Values...>
	 {};
}

template <>
inline constexpr std :: nullptr_t crap :: dataType <> :: data() noexcept
{
 return nullptr;
}
#endif

