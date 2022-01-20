#ifndef CRAP_UTILITY_PRINTFORTYPE
#define CRAP_UTILITY_PRINTFORTYPE

#include "printvalue.h"

namespace crap
{
 template <class Type> struct printForType
 {
  template <Type ... Values> using type = printValue<Type, Values...>;
  template <Type ... Values> using values = printValue<Type, Values...>;
 };
}
#endif

