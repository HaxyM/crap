#ifndef CRAP_ALGORITHM_EQUALFORTYPE
#define CRAP_ALGORITHM_EQUALFORTYPE

#include "equalvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template EqualTo> struct equalForType
 {
  template <Type ... Values> using type = equalValue<Type, Operator, Values...>;
  template <Type ... Values> using values = equalValue<Type, Operator, Values...>;
 };
}
#endif
