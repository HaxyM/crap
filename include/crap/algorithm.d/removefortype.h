#ifndef CRAP_ALGORITHM_REMOVEFORTYPE
#define CRAP_ALGORITHM_REMOVEFORTYPE

#include "removevalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, Type Value, template <Type, Type> class Operator = comparatorsForType <Type> :: template EqualTo>
	 struct removeForType
 {
  template <Type ... Values> using type = removeValue<Type, Value, Operator, Values...>;
  template <Type ... Values> using values = removeValue<Type, Value, Operator, Values...>;
 };
}
#endif

