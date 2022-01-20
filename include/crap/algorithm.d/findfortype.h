#ifndef CRAP_ALGORITHM_FINDFORTYPE
#define CRAP_ALGORITHM_FINDFORTYPE

#include "findvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, Type Value, template <Type, Type> class Operator = comparatorsForType <Type> :: template
	 EqualTo>
 struct findForType
 {
  template <Type ... Values> using type = findValue<Type, Value, Operator, Values...>;
  template <Type ... Values> using values = findValue<Type, Value, Operator, Values...>;
 };
}
#endif

