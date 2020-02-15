#ifndef CRAP_UTILITY_NULLFORTYPE
#define CRAP_UTILITY_NULLFORTYPE

#include "nullvalue.h"

namespace crap
{
 template <class Type> struct nullForType
 {
  template <Type ... Values> using type = nullValue<Type, Values...>;
  template <Type ... Values> using values = nullValue<Type, Values...>;
 };
}
#endif

