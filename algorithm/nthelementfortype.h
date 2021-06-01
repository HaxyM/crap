#ifndef CRAP_ALGORITHM_NTHELEMENTFORTYPE
#define CRAP_ALGORITHM_NTHELEMENTFORTYPE

#include <cstddef>

#include "minvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, std :: size_t N, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct NthElementForType
 {
  template <Type ... Values> using type = NthElementValue<Type, N, Operator, Values...>;
  template <Type ... Values> using values = NthElementValue<Type, N, Operator, Values...>;
 };
}
#endif

