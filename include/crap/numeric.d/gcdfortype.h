#ifndef CRAP_NUMERIC_GCDFORTYPE
#define CRAP_NUMERIC_GCDFORTYPE

#include "gcdvalue.h"

namespace crap
{
 template <class Type> struct gcdForType
 {
  template <Type ... Values> using type = gcdValue<Type, Values...>;
  template <Type ... Values> using values = gcdValue<Type, Values...>;
 };
}
#endif

