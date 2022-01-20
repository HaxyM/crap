#ifndef CRAP_ALGORITHM_INPLACEMERGEFORTYPE
#define CRAP_ALGORITHM_INPLACEMERGEFORTYPE

#include <cstddef>

#include "inplacemergevalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, std :: size_t Middle, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct inplaceMergeForType
 {
  template <Type ... Values> using type = inplaceMergeValue<Type, Middle, Operator, Values...>;
  template <Type ... Values> using values = inplaceMergeValue<Type, Middle, Operator, Values...>;
 };
}
#endif

