#ifndef CRAP_ALGORITHM_LOWERBOUNDFORTYPE
#define CRAP_ALGORITHM_LOWERBOUNDFORTYPE

#include "lowerboundvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, Type Value, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less> struct lowerBoundForType
 {
  template <Type ... Values> using type = lowerBoundValue<Type, Value, Operator, Values...>;
  template <Type ... Values> using values = lowerBoundValue<Type, Value, Operator, Values...>;
 };
}
#endif

