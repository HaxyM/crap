#ifndef CRAP_ITERATOR_SSIZEFORTYPE
#define CRAP_ITERATOR_SSIZEFORTYPE

#include "ssizevalue.h"

namespace crap
{
 template <class Type> struct ssizeForType
 {
  template <Type ... Values> using type = ssizeValue<Type, Values...>;
  template <Type ... Values> using values = ssizeValue<Type, Values...>;
 };
}
#endif

