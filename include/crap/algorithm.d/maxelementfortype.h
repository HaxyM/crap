#ifndef CRAP_ALGORITHM_MAXELEMENTFORTYPE
#define CRAP_ALGORITHM_MAXELEMENTFORTYPE

#include "maxelementvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct maxElementForType
 {
  template <Type ... Values> using type = maxElementValue<Type, Operator, Values...>;
  template <Type ... Values> using values = maxElementValue<Type, Operator, Values...>;
 };
}
#endif

