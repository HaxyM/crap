#ifndef CRAP_NUMERIC_INCLUSIVESCANFORTYPE
#define CRAP_NUMERIC_INCLUSIVESCANFORTYPE

#include "inclusivescanvalue.h"
#include "../functional.d/arithmeticoperatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = arithmeticOperatorsForType <Type> :: template Plus2>
	 struct inclusiveScanForType
 {
  template <Type ... Values> using values = inclusiveScanValue<Type, Operator, Values...>;
  template <Type ... Values> using type = inclusiveScanValue<Type, Operator, Values...>;
 };
}
#endif

