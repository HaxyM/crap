#ifndef CRAP_ALGORITHM_PULLHEAPFORTYPE
#define CRAP_ALGORITHM_PULLHEAPFORTYPE

#include "pullheapvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct pullHeapForType
 {
  template <Type ... Values> using type = pullHeapValue<Type, Operator, Values...>;
  template <Type ... Values> using values = pullHeapValue<Type, Operator, Values...>;
 };
}
#endif

