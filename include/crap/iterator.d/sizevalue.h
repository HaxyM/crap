#ifndef CRAP_ITERATOR_SIZEVALUE
#define CRAP_ITERATOR_SIZEVALUE

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <class Type, Type ... Values>
	 using sizeValue = std :: integral_constant<std :: size_t, sizeof...(Values)>;
}
#endif

