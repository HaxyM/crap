#ifndef CRAP_ALGORITHM_ISSORTEDFORTYPE
#define CRAP_ALGORITHM_ISSORTEDFORTYPE

#include "issortedvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Comparator = comparatorsForType <Type> :: template Less>
	 struct isSortedForType
 {
  template <Type ... Values> using values = isSortedValue<Type, Comparator, Values...>;
  template <Type ... Values> using type = isSortedValue<Type, Comparator, Values...>;
 };
}
#endif

