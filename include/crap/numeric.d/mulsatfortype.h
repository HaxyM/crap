#ifndef CRAP_NUMERIC_MULSATFORTYPE
#define CRAP_NUMERIC_MULSATFORTYPE

#include "mulsatvalue.h"

namespace crap
{
 template <class Type> struct mulSatForType
 {
  template <Type ... Values> using type = mulSatValue<Type, Values...>;
  template <Type ... Values> using values = mulSatValue<Type, Values...>;
 };
}
#endif

