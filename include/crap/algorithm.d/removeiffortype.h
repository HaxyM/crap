#ifndef CRAP_ALGORITHM_REMOVEIFFORTYPE
#define CRAP_ALGORITHM_REMOVEIFFORTYPE

#include "removeifvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator> struct removeIfForType
 {
  template <Type ... Values> using type = removeIfValue<Type, Operator, Values...>;
  template <Type ... Values> using values = removeIfValue<Type, Operator, Values...>;
 };
}
#endif

