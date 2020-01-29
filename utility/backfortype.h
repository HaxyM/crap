#ifndef CRAP_UTILITY_BACKFORTYPE
#define CRAP_UTILITY_BACKFORTYPE

#include "backvalue.h"

namespace crap
{
 template <class Type> struct backForType
 {
  template <Type ... Values> using type = backValue<Type, Values...>;
  template <Type ... Values> using values = backValues<Type, Values...>;
 };
}
#endif

