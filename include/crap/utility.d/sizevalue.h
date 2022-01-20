#ifndef CRAP_UTILITY_SIZEVALUE
#define CRAP_UTILITY_SIZEVALUE

#include <type_traits>
#include <utility>

namespace crap
{
 template <class Type, Type ... Values>
	 using sizeValue = std :: integral_constant<std :: size_t, sizeof...(Values)>;
}
#endif

