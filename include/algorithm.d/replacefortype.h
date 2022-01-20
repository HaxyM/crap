#ifndef CRAP_ALGORITHM_REPLACEFORTYPE
#define CRAP_ALGORITHM_REPLACEFORTYPE

#include "replacevalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, Type Old, Type New, template <Type, Type> class Operator = comparatorsForType <Type> :: template EqualTo>
	 struct replaceForType
 {
  template <Type ... Values> using type = replaceValue<Type, Old, New, Operator, Values...>;
  template <Type ... Values> using values = replaceValue<Type, Old, New, Operator, Values...>;
 };
}
#endif

