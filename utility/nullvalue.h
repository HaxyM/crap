#ifndef CRAP_UTILITY_NULLVALUE
#define CRAP_UTILITY_NULLVALUE

#include "valuelistfortype.h"

namespace crap
{
 template <class Type, Type ... Values> struct nullValue
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };
}
#endif

