#ifndef CRAP_ALGORITHM_MINMAXFORTYPE
#define CRAP_ALGORITHM_MINMAXFORTYPE

#include "minmaxvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct minMaxForType
 {
  template <Type ... Values> using type = minMaxValue<Type, Operator, Values...>;
  template <Type ... Values> using values = minMaxValue<Type, Operator, Values...>;
 };
}
#endif

