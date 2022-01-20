#ifndef CRAP_ALGORITHM_SEARCHFORTYPE
#define CRAP_ALGORITHM_SEARCHFORTYPE

#include "searchvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template EqualTo>
	 struct searchForType
 {
  template <Type ... Values> using type = searchValue<Type, Operator, Values...>;
  template <Type ... Values> using values = searchValue<Type, Operator, Values...>;
 };
}
#endif

