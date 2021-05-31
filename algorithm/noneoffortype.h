#ifndef CRAP_ALGORITHM_NONEOFFORTYPE
#define CRAP_ALGORITHM_NONEOFFORTYPE

#include "noneofvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator> struct noneOfForType
 {
  template <Type ... Values> using type = noneOfValue<Type, Operator, Values...>;
  template <Type ... Values> using values = noneOfValue<Type, Operator, Values...>;
 };
}
#endif

