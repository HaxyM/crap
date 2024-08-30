#ifndef CRAP_NUMERIC_REDUCEFORTYPE
#define CRAP_NUMERIC_REDUCEFORTYPE

#include "reducevalue.h"
#include "../functional.d/arithmeticoperatorsfortype.h"

namespace crap
{
 template <class Type, template <Type...> class Operator = arithmeticOperatorsForType <Type> :: template Plus>
	 struct reduceForType
 {
  template <Type ... Values> using type = reduceValue<Type, Operator, Values...>;
  template <Type ... Values> using values = reduceValue<Type, Operator, Values...>;
 };
}
#endif

