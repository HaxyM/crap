#ifndef CRAP_NUMERIC_LCMFORTYPE
#define CRAP_NUMERIC_LCMFORTYPE

#include "divsatvalue.h"

namespace crap
{
 template <class Type> struct lcmForType
 {
  template <Type ... Values> using type = lcmValue<Type, Values...>;
  template <Type ... Values> using values = lcmValue<Type, Values...>;
 };
}
#endif

