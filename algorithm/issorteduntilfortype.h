#ifndef CRAP_ALGORITHM_ISSORTEDUNTILFORTYPE
#define CRAP_ALGORITHM_ISSORTEDUNTILFORTYPE

#include "issorteduntil.h"
#include "../functional/comparatorsfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator = comparatorsForType <Type> :: template Less> struct isSortedUntilForType
 {
  template <Type ... Values> using type = isSortedUntilValue<Type, Operator, Values...>;
  template <Type ... Values> using values = isSortedUntilValue<Type, Operator, Values...>;
 };
}
#endif

