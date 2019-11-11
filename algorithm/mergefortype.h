#ifndef CRAP_ALGORITHM_MERGEFORTYPE
#define CRAP_ALGORITHM_MERGEFORTYPE

#include "mergevalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct mergeForType
 {
  template <Type ... Values> using type = mergeValue<Type, Operator, Values...>;
  template <Type ... Values> using values = mergeValue<Type, Operator, Values...>;
 };
}
#endif

