#ifndef CRAP_UTILITY_MERGEFORTYPE
#define CRAP_UTILITY_MERGEFORTYPE

namespace crap
{
 template <class Type> struct mergeForType;
}

#include "../utility/mergevalue.h"

namespace crap
{
 template <class Type> struct mergeForType
 {
  template <Type ... Values> using type = mergeValue<Type, Values...>;
  template <Type ... Values> using values = mergeValue<Type, Values...>;
 };
}
#endif

