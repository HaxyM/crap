#ifndef CRAP_ALGORITHM_ROTATEFORTYPE
#define CRAP_ALGORITHM_ROTATEFORTYPE

#include "rotatevalue.h"

#include <cstddef>

namespace crap
{
 template <class Type, std :: size_t N> struct rotateForType
 {
  template <Type ... Values> using type = rotateValue<N, Type, Values...>;
  template <Type ... Values> using values = rotateValue<N, Type, Values...>;
 };
}
#endif

