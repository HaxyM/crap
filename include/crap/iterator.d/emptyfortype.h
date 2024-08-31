#ifndef CRAP_ITERATOR_EMPTYFORTYPE
#define CRAP_ITERATOR_EMPTYFORTYPE

#include "emptyvalue.h"

namespace crap
{
 template <class Type> struct emptyForType
 {
  template <Type ... Values> using type = emptyValue<Type, Values...>;
  template <Type ... Values> using values = emptyValue<Type, Values...>;
 };
}
#endif

