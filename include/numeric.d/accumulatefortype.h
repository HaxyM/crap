#ifndef CRAP_NUMERIC_ACCUMULATEFORTYPE
#define CRAP_NUMERIC_ACCUMULATEFORTYPE

#include "accumulatevalue.h"
#include "../functional.d/arithmeticoperatorsfortype.h"

namespace crap
{
 template <class Type, template <Type...> class Operator = arithmeticOperatorsForType <Type> :: template Plus>
	 struct accumulateForType
 {
  template <Type ... Values> using type = accumulateValue<Type, Operator, Values...>;
  template <Type ... Values> using values = accumulateValue<Type, Operator, Values...>;
 };
}
#endif

