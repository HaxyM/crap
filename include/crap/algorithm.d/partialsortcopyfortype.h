#ifndef CRAP_ALGORITHM_PARTIALSORTCOPYFORTYPE
#define CRAP_ALGORITHM_PARTIALSORTCOPYFORTYPE

#include <cstddef>

#include "partialsortcopyvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, std :: size_t N, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct partialSortCopyForType
 {
  template <Type ... Values> using type = partialSortCopyValue<Type, N, Operator, Values...>;
  template <Type ... Values> using values = partialSortCopyValue<Type, N, Operator, Values...>;
 };
}
#endif

