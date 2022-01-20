#ifndef CRAP_ALGORITHM_INCLUDESFORTYPE
#define CRAP_ALGORITHM_INCLUDESFORTYPE

#include "includesvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
   struct includesForType
 {
  template <Type ... Values> using type = includesValue<Type, Operator, Values...>;
  template <Type ... Values> using values = includesValue<Type, Operator, Values...>;
 };
}
#endif
