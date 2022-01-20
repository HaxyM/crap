#ifndef CRAP_UTILITY_VALUELISTFORTYPE
#define CRAP_UTILITY_VALUELISTFORTYPE

namespace crap
{
 template <class Type> struct valueListForType;
}

#include "valuelist.h"

namespace crap
{
 template <class Type> struct valueListForType
 {
  template <Type... Values> using type = valueList<Type, Values...>;
 };
}
#endif

