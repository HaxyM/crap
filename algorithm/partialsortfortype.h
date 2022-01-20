#ifndef CRAP_ALGORITHM_PARTIALSORTFORTYPE
#define CRAP_ALGORITHM_PARTIALSORTFORTYPE

#include <cstddef>

#include "partialsortvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, std :: size_t N, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct partialSortForType
 {
  template <Type ... Values> using type = partialSortValue<Type, N, Operator, Values...>;
  template <Type ... Values> using values = partialSortValue<Type, N, Operator, Values...>;
 };
}
#endif

