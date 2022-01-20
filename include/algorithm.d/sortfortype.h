#ifndef CRAP_ALGORITHM_SORTFORTYPE
#define CRAP_ALGORITHM_SORTFORTYPE

#include "sortvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Comparator = comparatorsForType <Type> :: template Less>
	 struct sortForType
 {
  template <Type ... Values> using values = sortValue<Type, Comparator, Values...>;
  template <Type ... Values> using type = sortValue<Type, Comparator, Values...>;
 };
}
#endif

