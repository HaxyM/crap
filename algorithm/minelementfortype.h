#ifndef CRAP_ALGORITHM_MINELEMENTFORTYPE
#define CRAP_ALGORITHM_MINELEMENTFORTYPE

#include "minelementvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct minElementForType
 {
  template <Type ... Values> using type = minElementValue<Type, Operator, Values...>;
  template <Type ... Values> using values = minElementValue<Type, Operator, Values...>;
 };
}
#endif

