#ifndef CRAP_ALGORITHM_UPPERBOUNDFORTYPE
#define CRAP_ALGORITHM_UPPERBOUNDFORTYPE

#include "upperboundvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, Type Value, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less> struct upperBoundForType
 {
  template <Type ... Values> using type = upperBoundValue<Type, Value, Operator, Values...>;
  template <Type ... Values> using values = upperBoundValue<Type, Value, Operator, Values...>;
 };
}
#endif

