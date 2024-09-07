#ifndef CRAP_BIT_COUNTRONEFORTYPE
#define CRAP_BIT_COUNTRONEFORTYPE

#include "countronevalue.h"

namespace crap
{
 template <class Type> struct countrOneForType
 {
  template <Type Value> using type = countrOneValue<Type, Value>;
 };
}
#endif

