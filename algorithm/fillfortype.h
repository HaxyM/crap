#ifndef CRAP_ALGORITHM_FILLFORTYPE
#define CRAP_ALGORITHM_FILLFORTYPE

#include "fillvalue.h"

namespace crap
{
 template <class Type, Type Value> struct fillForType
 {
  template <Type ... Values> using type = fillValue<Type, Value, Values...>;
  template <Type ... Values> using values = fillValue<Type, Value, Values...>;
 };
}
#endif

