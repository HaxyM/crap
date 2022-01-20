#ifndef CRAP_UTILITY_SIZETYPE
#define CRAP_UTILITY_SIZETYPE

#include <type_traits>

namespace crap
{
 template <class ... Types> using sizeType = std :: integral_constant<std :: size_t, sizeof...(Types)>;
}
#endif

