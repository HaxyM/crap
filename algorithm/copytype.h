#ifndef CRAP_ALGORITHM_COPYTYPE
#define CRAP_ALGORITHM_COPYTYPE

#include "../utility/typelist.h"

namespace crap
{
 template <class ... Types> struct copyType
 {
  template <template <class...> class Container = typeList> using type = Container<Types...>;
 };
}
#endif

