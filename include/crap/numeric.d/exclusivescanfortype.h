#ifndef CRAP_NUMERIC_EXCLUSIVESCANFORTYPE
#define CRAP_NUMERIC_EXCLUSIVESCANFORTYPE

#include "exclusivescanvalue.h"
#include "../functional.d/arithmeticoperatorsfortype.h"

namespace crap
{
 template <class Type, Type Init, template <Type, Type> class Operator = arithmeticOperatorsForType <Type> :: template Plus2>
	 struct exclusiveScanForType
 {
  template <Type ... Values> using values = exclusiveScanValue<Type, Init, Operator, Values...>;
  template <Type ... Values> using type = exclusiveScanValue<Type, Init, Operator, Values...>;
 };
}
#endif

