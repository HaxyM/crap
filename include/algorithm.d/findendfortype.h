#ifndef CRAP_ALGORITHM_FINDENDFORTYPE
#define CRAP_ALGORITHM_FINDENDFORTYPE

#include "findendvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template EqualTo>
	 struct findEndForType
 {
  template <Type ... Values> using type = findEndValue<Type, Operator, Values...>;
  template <Type ... Values> using values = findEndValue<Type, Operator, Values...>;
 };
}
#endif

