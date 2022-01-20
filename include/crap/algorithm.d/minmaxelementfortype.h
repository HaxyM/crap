#ifndef CRAP_ALGORITHM_MINMAXELEMENTFORTYPE
#define CRAP_ALGORITHM_MINMAXELEMENTFORTYPE

#include "minmaxelementvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct minMaxElementForType
 {
  template <Type ... Values> using type = minMaxElementValue<Type, Operator, Values...>;
  template <Type ... Values> using values = minMaxElementValue<Type, Operator, Values...>;
 };
}
#endif

