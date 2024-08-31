#ifndef CRAP_ITERATOR_SIZETYPE
#define CRAP_ITERATOR_SIZETYPE

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <class ... Types> using sizeType = std :: integral_constant<std :: size_t, sizeof...(Types)>;
}
#endif

