#ifndef CRAP_ALGORITHM_ISPERMUTATIONFORTYPE
#define CRAP_ALGORITHM_ISPERMUTATIONFORTYPE

#include "ispermutationvalue.h"
#include "../functional.d/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template EqualTo>
	 struct isPermutationForType
 {
  template <Type ... Values> using type = isPermutationValue<Type, Operator, Values...>;
  template <Type ... Values> using values = isPermutationValue<Type, Operator, Values...>;
 };
}
#endif

