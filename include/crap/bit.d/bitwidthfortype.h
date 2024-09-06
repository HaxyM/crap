#ifndef CRAP_BIT_BITWIDTHFORTYPE
#define CRAP_BIT_BITWIDTHFORTYPE

#include "bitwidthvalue.h"

namespace crap
{
 template <class Type> struct bitWidthForType
 {
  template <Type Value> using type = bitWidthValue<Type, Value>;
 };
}
#endif

