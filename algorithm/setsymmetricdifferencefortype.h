#ifndef CRAP_ALGORITHM_SETSYMMETRICDIFFERENCEFORTYPE
#define CRAP_ALGORITHM_SETSYMMETRICDIFFERENCEFORTYPE

#include "setsymmetricdifferencevalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct setSymmetricDifferenceForType
 {
  template <Type ... Values> using type = setSymmetricDifferenceValue<Type, Operator, Values...>;
  template <Type ... Values> using values = setSymmetricDifferenceValue<Type, Operator, Values...>;
 };
}
#endif

