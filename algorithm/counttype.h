#ifndef CRAP_ALGORITHM_COUNTTYPE
#define CRAP_ALGORITHM_COUNTTYPE

#include <type_traits>

namespace crap
{
 template <class ... Types> using countType = std :: integral_constant<std :: size_t, sizeof...(Types)>;
}
#endif

