#ifndef CRAP_ALGORITHM_COPYVALUE
#define CRAP_ALGORITHM_COPYVALUE

#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, Type ... Values> struct copyValue
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Values...>;
 };
}
#endif

