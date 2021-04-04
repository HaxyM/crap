#ifndef CRAP_UTILITY_ERASETYPE
#define CRAP_UTILITY_ERASETYPE

#include "concatenatetype.h"
#include "typelist.h"

namespace crap
{
 template <std :: size_t Begin, std :: size_t End, class ... Types> struct eraseType
 {
  private:
  using values = typeList<Types...>;
  static_assert(Begin <= End, "Negative range not supported.");
  static_assert(End <= (values :: size), "Index out of range.");
  static_assert(Begin <= (values :: size), "Index out of range.");
  public:
  template <template <class...> class Container = typeList>
	  using type = typename values :: template
	  since <End, values :: template till <Begin, concatenateType> :: template with> :: template
	  type<Container>;
 };
}
#endif

