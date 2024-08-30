#ifndef CRAP_NUMERIC_ADDSATFORTYPE
#define CRAP_NUMERIC_ADDSATFORTYPE

#include "addsatvalue.h"

namespace crap
{
 template <class Type> struct addSatForType
 {
  template <Type ... Values> using type = addSatValue<Type, Values...>;
  template <Type ... Values> using values = addSatValue<Type, Values...>;
 };
}
#endif

