#ifndef CRAP_NUMERIC_DIVSATFORTYPE
#define CRAP_NUMERIC_DIVSATFORTYPE

#include "divsatvalue.h"

namespace crap
{
 template <class Type> struct divSatForType
 {
  template <Type ... Values> using type = divSatValue<Type, Values...>;
  template <Type ... Values> using values = divSatValue<Type, Values...>;
 };
}
#endif

