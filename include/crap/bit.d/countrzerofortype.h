#ifndef CRAP_BIT_COUNTRZEROFORTYPE
#define CRAP_BIT_COUNTRZEROFORTYPE

#include "countrzerovalue.h"

namespace crap
{
 template <class Type> struct countrZeroForType
 {
  template <Type Value> using type = countrZeroValue<Type, Value>;
 };
}
#endif

