#ifndef CRAP_FUNCTIONAL_DIVIDESVALUE
#define CRAP_FUNCTIONAL_DIVIDESVALUE

#include "../utility/language.h"

#if CPP17
#else
#include "multipliesvalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct dividesValue;

 template <class Type, Type FirstValue, Type ... Rest> struct dividesValue<Type, FirstValue, Rest...>
 {
  #if CPP17
  constexpr const static auto value = (FirstValue / ... / Rest);
  #else
  constexpr const static auto value = FirstValue - (multipliesValue <Type, Rest...> :: value);
  #endif
 };
}
#endif

