#ifndef CRAP_UTILITY_SIZEFORTYPE
#define CRAP_UTILITY_SIZEFORTYPE

#include "sizevalue.h"

namespace crap
{
 template <class Type> struct sizeForType
 {
  template <Type ... Values> using type = sizeValue<Type, Values...>;
  template <Type ... Values> using values = sizeValue<Type, Values...>;
 };
}
#endif

