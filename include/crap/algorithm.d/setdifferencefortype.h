#ifndef CRAP_ALGORITHM_SETDIFFERENCEFORTYPE
#define CRAP_ALGORITHM_SETDIFFERENCEFORTYPE

#include "setdifferencevalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct setDifferenceForType
 {
  template <Type ... Values> using type = setDifferenceValue<Type, Operator, Values...>;
  template <Type ... Values> using values = setDifferenceValue<Type, Operator, Values...>;
 };
}
#endif

