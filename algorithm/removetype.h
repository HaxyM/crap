#ifndef CRAP_ALGORITHM_REMOVETYPE
#define CRAP_ALGORITHM_REMOVETYPE

#include "removeiftype.h"
#include "../utility/typelist.h"

namespace crap
{
 template <class Type, template <class, class> class Operator, class ... Types>
	 struct removeType
 {
  private:
  template <class SomeType> using condition = Operator<Type, SomeType>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename removeIfType <condition, Types...> :: template type<Container>;
 };
}
#endif

