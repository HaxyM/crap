#ifndef CRAP_NUMERIC_OUTERPRODUCTFORTYPE
#define CRAP_NUMERIC_OUTERPRODUCTFORTYPE

#include "outerproductvalue.h"
#include "../functional/arithmeticoperatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = arithmeticOperatorsForType <Type> :: template Multiplies2>
	 struct outerProductForType
 {
  template <Type ... Values> using type = outerProductValue<Type, Operator, Values...>;
  template <Type ... Values> using values = outerProductValue<Type, Operator, Values...>;
 };
}
#endif

