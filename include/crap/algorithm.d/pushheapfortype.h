#ifndef CRAP_ALGORITHM_PUSHHEAPFORTYPE
#define CRAP_ALGORITHM_PUSHHEAPFORTYPE

#include "pushheapvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct pushHeapForType
 {
  template <Type ... Values> using type = pushHeapValue<Type, Operator, Values...>;
  template <Type ... Values> using values = pushHeapValue<Type, Operator, Values...>;
 };
}
#endif

