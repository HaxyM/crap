#ifndef CRAP_ALGORITHM_TRANSFORM2FORTYPE
#define CRAP_ALGORITHM_TRANSFORM2FORTYPE

#include "transform2value.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator> struct transform2ForType
 {
  template <Type ... Values> using type = transform2Value<Type, Operator, Values...>;
  template <Type ... Values> using values = transform2Value<Type, Operator, Values...>;
 };
}
#endif

