#ifndef CRAP_ALGORITHM_MINFORTYPE
#define CRAP_ALGORITHM_MINFORTYPE

#include "minvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct minForType
 {
  template <Type ... Values> using type = minValue<Type, Operator, Values...>;
  template <Type ... Values> using values = minValue<Type, Operator, Values...>;
 };
}
#endif

