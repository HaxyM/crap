#ifndef CRAP_ALGORITHM_TRANSFORMVALUE
#define CRAP_ALGORITHM_TRANSFORMVALUE

#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type> class Operator, Type ... Values> struct transformValue
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<(Operator <Values> :: value)...>;
 };
}
#endif

