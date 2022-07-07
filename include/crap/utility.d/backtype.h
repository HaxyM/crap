#ifndef CRAP_UTILITY_BACKTYPE
#define CRAP_UTILITY_BACKTYPE

#include "typelist.h"

namespace crap
{
 template <class...> struct backType;

 template <class First, class ... Rest> struct backType<First, Rest...>
 {
  using type = typename typeList <First, Rest...> :: template at<sizeof...(Rest)>;
  template <template <class...> class Container>
	  using pop = typename typeList <First, Rest...> :: template till<sizeof...(Rest), Container>;
 };

 template <class ... Types> struct backType
 {
  static_assert(sizeof...(Types) != 0u, "Collection must not be empty.");
 };

 template <class ... Types> using backType_t = typename backType <Types...> :: type;
}
#endif
