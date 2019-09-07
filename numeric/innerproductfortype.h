#ifndef CRAP_NUMERIC_INNERPRODUCTFORTYPE
#define CRAP_NUMERIC_INNERPRODUCTFORTYPE

#include "innerproductvalue.h"
#include "../functional/arithmeticoperatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class AdditiveOperator = arithmeticOperatorsForType <Type> :: template Plus2, template <Type, Type> class MultiplicativeOperator = arithmeticOperatorsForType <Type> :: template Multiplies2>
	 struct innerProductForType
 {
  template <Type ... Values1> using values = innerProductValue<Type, AdditiveOperator, MultiplicativeOperator, Values1...>;
  template <Type ... Values1> using type = innerProductValue<Type, AdditiveOperator, MultiplicativeOperator, Values1...>;
 };
}
#endif

