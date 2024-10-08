#ifndef CRAP_ITERATOR_EMPTYVALUE
#define CRAP_ITERATOR_EMPTYVALUE

#include <type_traits>

namespace crap
{
 template <class Type, Type ... Values> using emptyValue = std :: integral_constant<bool, sizeof...(Values) == 0u>;
}
#endif

