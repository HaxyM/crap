#ifndef CRAP_ALGORITHM_REVERSEFORTYPE
#define CRAP_ALGORITHM_REVERSEFORTYPE

#include "reversevalue.h"

namespace crap
{
 template <class Type> struct reverseForType
 {
  template <Type ... Values> using type = reverseValue<Type, Values...>;
  template <Type ... Values> using values = reverseValue<Type, Values...>;
 };
}
#endif

