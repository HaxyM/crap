#ifndef CRAP_ALGORITHM_SEARCHALLFORTYPE
#define CRAP_ALGORITHM_SEARCHALLFORTYPE

#include "searchallvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template EqualTo>
	 struct searchAllForType
 {
  template <Type ... Pattern> using type = searchAllValue<Type, Operator, Pattern...>;
  template <Type ... Pattern> using pattern = searchAllValue<Type, Operator, Pattern...>;
 };
}
#endif

