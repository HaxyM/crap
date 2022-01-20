#ifndef CRAP_UTILITY_BISECTFORTYPE
#define CRAP_UTILITY_BISECTFORTYPE

#include "bisectvalue.h"

namespace crap
{
 template <class Type> struct bisectForType
 {
  template <Type ... Values> using type = bisectValue<Type, Values...>;
  template <Type ... Values> using values = bisectValues<Type, Values...>;
 };
}
#endif

