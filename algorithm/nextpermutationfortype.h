#ifndef CRAP_ALGORITHM_NEXTPERMUTATIONFORTYPE
#define CRAP_ALGORITHM_NEXTPERMUTATIONFORTYPE

#include "nextpermutationvalue.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less>
	 struct nextPermutationForType
 {
  template <Type ... Values> using type = nextPermutationValue<Type, Operator, Values...>;
  template <Type ... Values> using values = nextPermutationValue<Type, Operator, Values...>;
 };
}
#endif

