#ifndef CRAP_ALGORITHM_PREVPERMUTATIONFORTYPE
#define CRAP_ALGORITHM_PREVPERMUTATIONFORTYPE

#include "prevpermutationvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct prevPermutationForType
 {
  template <Type ... Values> using type = prevPermutationValue<Type, Operator, Values...>;
  template <Type ... Values> using values = prevPermutationValue<Type, Operator, Values...>;
 };
}
#endif

