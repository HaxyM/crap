#ifndef CRAP_NUMERIC_SUBSATFORTYPE
#define CRAP_NUMERIC_SUBSATFORTYPE

#include "subsatvalue.h"

namespace crap
{
 template <class Type> struct subSatForType
 {
  template <Type ... Values> using type = subSatValue<Type, Values...>;
  template <Type ... Values> using values = subSatValue<Type, Values...>;
 };
}
#endif

