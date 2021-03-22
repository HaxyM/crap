#ifndef CRAP_ALGORITHM_FILLTYPE
#define CRAP_ALGORITHM_FILLTYPE

#include "../utility/typelist.h"

namespace crap
{
 template <class Type, class ... Types> struct fillType
 {
  private:
  template <class> using coma = Type;
  public:
  template <template <class...> class Container = typeList>
	  using type = Container<coma<Types>...>;
 };
}
#endif

