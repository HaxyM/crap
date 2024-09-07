#ifndef CRAP_BIT_HASSINGLEBITFORTYPE
#define CRAP_BIT_HASSINGLEBITFORTYPE

#include "hassinglebitvalue.h"

namespace crap
{
 template <class Type> struct hasSingleBitForType
 {
  template <Type Value> using type = hasSingleBitValue<Type, Value>;
 };
}
#endif

