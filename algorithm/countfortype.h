#ifndef CRAP_ALGORITHM_COUNTFORTYPE
#define CRAP_ALGORITHM_COUNTFORTYPE

#include "countvalue.h"

namespace crap
{
 template <class Type> struct countForType
 {
  template <Type ... Values> using type = countValue<Type, Values...>;
  template <Type ... Values> using values = countValue<Type, Values...>;
 };
}
#endif

