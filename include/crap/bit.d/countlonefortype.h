#ifndef CRAP_BIT_COUNTLONEFORTYPE
#define CRAP_BIT_COUNTLONEFORTYPE

#include "countlonevalue.h"

namespace crap
{
 template <class Type> struct countlOneForType
 {
  template <Type Value> using type = countlOneValue<Type, Value>;
 };
}
#endif

