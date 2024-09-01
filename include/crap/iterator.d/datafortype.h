#ifndef CRAP_ITERATOR_DATAFORTYPE
#define CRAP_ITERATOR_DATAFORTYPE

#include "datavalue.h"

namespace crap
{
 template <class Type> struct dataForType
 {
  template <Type ... Values> using type = dataValue<Type, Values...>;
  template <Type ... Values> using values = dataValue<Type, Values...>;
 };
}
#endif

