#ifndef CRAP_ALGORITHM_FILLVALUE
#define CRAP_ALGORITHM_FILLVALUE

#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, Type Value, Type ... Values> struct fillValue
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<(Values,Value)...>;
 };
}
#endif

