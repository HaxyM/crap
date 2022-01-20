#ifndef CRAP_UTILITY_SPLITTYPE
#define CRAP_UTILITY_SPLITTYPE

#include "typelist.h"

namespace crap
{
 template <std :: size_t At, class ... Types> struct splitType
 {
  static_assert(At <= sizeof...(Types), "Index out of range.");
  template <template <class...> class Container = typeList>
	  using lower = typename typeList <Types...> :: template till<At, Container>;
  template <template <class...> class Container = typeList>
	  using upper = typename typeList <Types...> :: template since<At, Container>;
 };
}
#endif

