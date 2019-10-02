#ifndef CRAP_ALGORITHM_SETUNIONFORTYPE
#define CRAP_ALGORITHM_SETUNIONFORTYPE

#include "setunionvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct setUnionForType
 {
  template <Type ... Values> using type = setUnionValue<Type, Operator, Values...>;
  template <Type ... Values> using values = setUnionValue<Type, Operator, Values...>;
 };
}
#endif

