#ifndef CRAP_UTILITY_EMPTYFORTYPE
#define CRAP_UTILITY_EMPTYFORTYPE

#include "emptyvalue.h"

namespace crap
{
 template <class Type> struct emptyForType
 {
  template <Type ... Values> using type = emptyValue<Type, Values...>;
  template <Type ... Values> using values = emptyValue<Type, Values...>;
 };
}
#endif

