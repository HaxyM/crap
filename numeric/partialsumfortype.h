#ifndef CRAP_NUMERIC_PARTIALSUMFORTYPE
#define CRAP_NUMERIC_PARTIALSUMFORTYPE

#include "partialsumvalue.h"
#include "../functional/arithmeticoperatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = arithmeticOperatorsForType <Type> :: template Plus2>
	 struct partialSumForType
 {
  template <Type ... Values> using values = partialSumValue<Type, Operator, Values...>;
  template <Type ... Values> using type = partialSumValue<Type, Operator, Values...>;
 };
}
#endif

