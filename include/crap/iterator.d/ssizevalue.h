#ifndef CRAP_ITERATOR_SSIZEVALUE
#define CRAP_ITERATOR_SSIZEVALUE

#include <cstddef>
#include <type_traits>

#include "../numeric.d/saturatecastvalue.h"
#include "../utility.d/inrangevalue.h"

namespace crap
{
 template <class Type, Type ... Values> struct ssizeValue
	 : std :: integral_constant<std :: ptrdiff_t,
     	 saturateCastValue <std :: ptrdiff, decltype(sizeof...(Values)), sizeof...(Values)> :: value>
 {
  static_assert(inRangeValue <std :: ptrdiff, decltype(sizeof...(Values)), sizeof...(Values)> :: value,
	  "Out of range.");
 };
}
#endif

