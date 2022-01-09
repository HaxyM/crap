#ifndef CRAP_ALGORITHM_FINDIFFORTYPE
#define CRAP_ALGORITHM_FINDIFFORTYPE

#include "findifvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator> struct findIfForType
 {
  template <Type ... Values> using type = findIfValue<Type, Operator, Values...>;
  template <Type ... Values> using values = findIfValue<Type, Operator, Values...>;
 };
}
#endif

