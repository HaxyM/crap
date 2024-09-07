#ifndef CRAP_BIT_POPCOUNTFORTYPE
#define CRAP_BIT_POPCOUNTFORTYPE

#include "popcountvalue.h"

namespace crap
{
 template <class Type> struct popcountForType
 {
  template <Type Value> using type = popcountValue<Type, Value>;
 };
}
#endif

