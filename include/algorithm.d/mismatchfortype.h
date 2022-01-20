#ifndef CRAP_ALGORITHM_MISMATCHFORTYPE
#define CRAP_ALGORITHM_MISMATCHFORTYPE

#include "mismatchvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template EqualTo>
	 struct mismatchForType
 {
  template <Type ... Values> using type = mismatchValue<Type, Operator, Values...>;
  template <Type ... Values> using values = mismatchValue<Type, Operator, Values...>;
 };
}
#endif

