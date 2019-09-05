#ifndef CRAP_FUNCTIONAL_MINUSVALUE
#define CRAP_FUNCTIONAL_MINUSVALUE

#include "../utility/language.h"

#if CPP17
#else
#include "plusvalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct minusValue;

 template <class Type, Type FirstValue, Type ... Rest> struct minusValue<Type, FirstValue, Rest...>
 {
  #if CPP17
  constexpr const static auto value = (FirstValue - ... - Rest);
  #else
  constexpr const static auto value = FirstValue - (plusValue <Type, Rest...> :: value);
  #endif
 };
}
#endif

