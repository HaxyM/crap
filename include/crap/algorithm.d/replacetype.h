#ifndef CRAP_ALGORITHM_REPLACETYPE
#define CRAP_ALGORITHM_REPLACETYPE

#include "../utility.d/typelist.h"

#include <type_traits>

namespace crap
{
 template <class Old, class New, template <class, class> class Operator, class ... Types>
	 struct replaceType
 {
  private:
  template <class Type>
	  using properType = typename std :: conditional<(Operator <Type, Old> :: value), New, Type> :: type;
  public:
  template <template <class...> class Container = typeList>
	  using type = Container<properType<Types>...>;
 };
}
#endif

