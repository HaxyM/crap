#ifndef CRAP_ALGORITHM_SETINTERSECTIONFORTYPE
#define CRAP_ALGORITHM_SETINTERSECTIONFORTYPE

#include "setintersectionvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct setIntersectionForType
 {
  template <Type ... Values> using type = setIntersectionValue<Type, Operator, Values...>;
  template <Type ... Values> using values = setIntersectionValue<Type, Operator, Values...>;
 };
}
#endif

