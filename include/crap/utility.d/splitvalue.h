#ifndef CRAP_UTILITY_SPLITVALUE
#define CRAP_UTILITY_SPLITVALUE

#include "valuelist.h"
#include "valuelistfortype.h"

namespace crap
{
 template <std :: size_t At, class Type, Type ... Values> struct splitValue
 {
  static_assert(At <= sizeof...(Values), "Index out of range.");
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using lower = typename valueList <Type, Values...> :: template till<At, Container>;
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using upper = typename valueList <Type, Values...> :: template since<At, Container>;
 };
}
#endif

