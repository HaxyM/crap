#ifndef CRAP_ALGORITHM_COUNTFORTYPE
#define CRAP_ALGORITHM_COUNTFORTYPE

#include "countvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, Type Value, template <Type, Type> class Operator = comparatorsForType <Type> :: template
	 EqualTo>
 struct countForType
 {
  template <Type ... Values> using type = countValue<Type, Value, Operator, Values...>;
  template <Type ... Values> using values = countValue<Type, Value, Operator, Values...>;
 };
}
#endif

