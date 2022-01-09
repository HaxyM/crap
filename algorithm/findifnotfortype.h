#ifndef CRAP_ALGORITHM_FINDIFNOTFORTYPE
#define CRAP_ALGORITHM_FINDIFNOTFORTYPE

#include "findifnotvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator> struct findIfNotForType
 {
  template <Type ... Values> using type = findIfNotValue<Type, Operator, Values...>;
  template <Type ... Values> using values = findIfNotValue<Type, Operator, Values...>;
 };
}
#endif

