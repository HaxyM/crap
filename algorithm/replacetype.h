#ifndef CRAP_ALGORITHM_REPLACETYPE
#define CRAP_ALGORITHM_REPLACETYPE

#include "../utility/typelist.h"

#include <type_traits>

namespace crap
{
 template <class Old, class New, template <class, class> class Operator, class ... Types>
	 struct replaceType
 {
  private:
  template <class Type>
	  using type = typename std :: conditional<(Operator <Type, Old> :: value), New : Type> :: type;
  public:
  template <template <class...> class Container = typeList>
	  using type = Container<(type<Types>...>;
 };
}
#endif

