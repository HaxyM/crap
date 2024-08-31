#ifndef CRAP_ITERATOR_EMPTYTYPE
#define CRAP_ITERATOR_EMPTYTYPE

#include <type_traits>

namespace crap
{
 template <class ... Types> using emptyType = std :: integral_constant<bool, sizeof...(Types) == 0u>;
}
#endif

