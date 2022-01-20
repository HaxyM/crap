#ifndef CRAP_ALGORTIHM_COPYIFFORTYPE
#define CRAP_ALGORTIHM_COPYIFFORTYPE

#include "copyifvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator> struct copyIfForType
 {
  template <Type ... Values> using type = copyIfValue<Type, Operator, Values...>;
  template <Type ... Values> using values = copyIfValue<Type, Operator, Values...>;
 };
}
#endif

