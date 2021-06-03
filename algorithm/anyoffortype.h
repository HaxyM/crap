#ifndef CRAP_ALGORITHM_ANYOFFORTYPE
#define CRAP_ALGORITHM_ANYOFFORTYPE

#include "anyofvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator> struct anyOfForType
 {
  template <Type ... Values> using type = anyOfValue<Type, Operator, Values...>;
  template <Type ... Values> using values = anyOfValue<Type, Operator, Values...>;
 };
}
#endif

