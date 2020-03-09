#ifndef CRAP_UTILITY_CONCATENATETYPE
#define CRAP_UTILITY_CONCATENATETYPE

#include "typelist.h"

namespace crap
{
 template <class ... Types1> struct concatenateType
 {
  template <class ... Types2> using with = concatenateType<Types1..., Types2...>;
  template <template <class...> class Container = typeList> using type = Container<Types1...>;
 };
}
#endif

