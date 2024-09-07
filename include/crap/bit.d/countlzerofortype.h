#ifndef CRAP_BIT_COUNTLZEROFORTYPE
#define CRAP_BIT_COUNTLZEROFORTYPE

#include "countlzerovalue.h"

namespace crap
{
 template <class Type> struct countlZeroForType
 {
  template <Type Value> using type = countlZeroValue<Type, Value>;
 };
}
#endif

