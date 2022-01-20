#ifndef CRAP_ALGORITHM_MAKEHEAPFORTYPE
#define CRAP_ALGORITHM_MAKEHEAPFORTYPE

#include "makeheapvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Comparator = comparatorsForType <Type> :: template Less>
	 struct makeHeapForType
 {
  template <Type ... Values> using values = makeHeapValue<Type, Comparator, Values...>;
  template <Type ... Values> using type = makeHeapValue<Type, Comparator, Values...>;
 };
}
#endif

