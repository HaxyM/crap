#ifndef CRAP_BIT_BITFLOORFORTYPE
#define CRAP_BIT_BITFLOORFORTYPE

#include "bitfloorvalue.h"

namespace crap
{
 template <class Type> struct bitFloorForType
 {
  template <Type Value> using type = bitFloorValue<Type, Value>;
 };
}
#endif

