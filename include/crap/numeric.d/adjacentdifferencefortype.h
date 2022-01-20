#ifndef CRAP_NUMERIC_ADJACENTDIFFERENCEFORTYPE
#define CRAP_NUMERIC_ADJACENTDIFFERENCEFORTYPE

#include "adjacentdifferencevalue.h"
#include "../functional.d/arithmeticoperatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = arithmeticOperatorsForType <Type> :: template Minus2>
	 struct adjacentDifferenceForType
 {
  template <Type ... Values> using values = adjacentDifferenceValue<Type, Operator, Values...>;
  template <Type ... Values> using type = adjacentDifferenceValue<Type, Operator, Values...>;
 };
}
#endif

