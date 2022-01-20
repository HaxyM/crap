#ifndef CRAP_ALGORITHM_COPYFORTYPE
#define CRAP_ALGORITHM_COPYFORTYPE

#include "copyvalue.h"

namespace crap
{
 template <class Type> struct copyForType
 {
  template <Type ... Values> using type = copyValue<Type, Values...>;
  template <Type ... Values> using values = copyValue<Type, Values...>;
 };
}
#endif

