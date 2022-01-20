#ifndef CRAP_ALGORITHM_ALLOFFORTYPE
#define CRAP_ALGORITHM_ALLOFFORTYPE

#include "allofvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator> struct allOfForType
 {
  template <Type ... Values> using type = allOfValue<Type, Operator, Values...>;
  template <Type ... Values> using values = allOfValue<Type, Operator, Values...>;
 };
}
#endif

