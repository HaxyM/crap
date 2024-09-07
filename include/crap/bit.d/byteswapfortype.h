#ifndef CRAP_BIT_BYTESWAPFORTYPE
#define CRAP_BIT_BYTESWAPFORTYPE

#include "byteswapvalue.h"

namespace crap
{
 template <class Type> struct byteswapForType
 {
  template <Type Value> using type = byteswapValue<Type, Value>;
 };
}
#endif

