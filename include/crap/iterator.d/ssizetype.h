#ifndef CRAP_ITERATOR_SSIZETYPE
#define CRAP_ITERATOR_SSIZETYPE

#include <cstddef>
#include <type_traits>

#include "../numeric.d/saturatecastvalue.h"
#include "../utility.d/inrangevalue.h"

namespace crap
{
 template <class ... Types> struct ssizeType
	 : std :: integral_constant<std :: ptrdiff_t,
     	 saturateCastValue <std :: ptrdiff, decltype(sizeof...(Types)), sizeof...(Types)> :: value>
 {
  static_assert(inRangeValue <std :: ptrdiff, decltype(sizeof...(Types)), sizeof...(Types)> :: value,
	  "Out of range.");
 };
}
#endif

