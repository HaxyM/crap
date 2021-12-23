#ifndef CRAP_ALGORITHM_FINDFIRSTOFFORTYPE
#define CRAP_ALGORITHM_FINDFIRSTOFFORTYPE

#include "findfirstofvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template EqualTo>
	 struct findFirstOfForType
 {
  template <Type ... Keys> using type = findFirstOfValue<Type, Operator, Keys...>;
  template <Type ... Keys> using values = findFirstOfValue<Type, Operator, Keys...>;
 };
}
#endif

