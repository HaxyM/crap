#ifndef CRAP_ALGORITHM_UNIQUEFORTYPE
#define CRAP_ALGORITHM_UNIQUEFORTYPE

#include "uniquevalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type,Type> class Operator = comparatorsForType <Type> :: template EqualTo>
	 struct uniqueForType
 {
  template <Type ... Values> using type = uniqueValue<Type, Operator, Values...>;
  template <Type ... Values> using values = uniqueValue<Type, Operator, Values...>;
 };
}
#endif

