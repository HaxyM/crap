#ifndef CRAP_ALGORITHM_INPLACEMERGETYPE
#define CRAP_ALGORITHM_INPLACEMERGETYPE

#include <cstddef>

#include "mergetype.h"
#include "../utility/splittype.h"
#include "../utility/typelist.h"

namespace crap
{
 template <std :: size_t Middle, template <class, class> class Operator, class ... Types>
	 struct inplaceMergeType
 {
  private:
  template <class ... SubTypes> using merge = mergeType<Operator, SubTypes...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename splitType <Middle, Types...> :: template
	  upper<splitType <Middle, Types...> :: template lower <merge> :: template with> :: template
	  type<Container>;
 };
}
#endif

