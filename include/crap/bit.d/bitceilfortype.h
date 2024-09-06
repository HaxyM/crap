#ifndef CRAP_BIT_BITCEILFORTYPE
#define CRAP_BIT_BITCEILFORTYPE

#include "bitceilvalue.h"

namespace crap
{
 template <class Type> struct bitCeilForType
 {
  template <Type Value> using type = bitCeilValue<Type, Value>;
 };
}
#endif

