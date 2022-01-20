#ifndef CRAP_ALGORITHM_ISHEAPFORTYPE
#define CRAP_ALGORITHM_ISHEAPFORTYPE

#include "isheapvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct isHeapForType
 {
  template <Type ... Values> using type = isHeapValue<Type, Operator, Values...>;
  template <Type ... Values> using values = isHeapValue<Type, Operator, Values...>;
 };
}
#endif

