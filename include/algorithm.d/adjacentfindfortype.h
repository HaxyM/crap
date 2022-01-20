#ifndef CRAP_ALGORITHM_ADJACENTFINDFORTYPE
#define CRAP_ALGORITHM_ADJACENTFINDFORTYPE

#include "adjacentfindvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template EqualTo>
	 struct adjacentFindForType
 {
  template <Type ... Values> using type = adjacentFindValue<Type, Operator, Values...>;
  template <Type ... Values> using values = adjacentFindValue<Type, Operator, Values...>;
 };
}
#endif

