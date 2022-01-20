#ifndef CRAP_ALGORITHM_SORTHEAPFORTYPE
#define CRAP_ALGORITHM_SORTHEAPFORTYPE

#include "sortheapvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct sortHeapForType
 {
  template <Type ... Values> using type = sortHeapValue<Type, Operator, Values...>;
  template <Type ... Values> using values = sortHeapValue<Type, Operator, Values...>;
 };
}
#endif

