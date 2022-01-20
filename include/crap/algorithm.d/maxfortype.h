#ifndef CRAP_ALGORITHM_MAXFORTYPE
#define CRAP_ALGORITHM_MAXFORTYPE

#include "maxvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct maxForType
 {
  template <Type ... Values> using type = maxValue<Type, Operator, Values...>;
  template <Type ... Values> using values = maxValue<Type, Operator, Values...>;
 };
}
#endif

