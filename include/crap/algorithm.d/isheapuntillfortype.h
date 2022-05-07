#ifndef CRAP_ALGORITHM_ISHEAPUNTILLFORTYPE
#define CRAP_ALGORITHM_ISHEAPUNTILLFORTYPE

#include "isheapuntillvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct isHeapUntillForType
 {
  template <Type ... Values> using type = isHeapUntillValue<Type, Operator, Values...>;
  template <Type ... Values> using values = isHeapUntillValue<Type, Operator, Values...>;
 };
}
#endif

