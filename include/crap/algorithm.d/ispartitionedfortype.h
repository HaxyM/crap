#ifndef CRAP_ALGORITHM_ISPARTITIONEDFORTYPE
#define CRAP_ALGORITHM_ISPARTITIONEDFORTYPE

#include "ispartitionedvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator> struct isPartitionedForType
 {
  template <Type ... Values> using type = isPartitionedValue<Type, Operator, Values...>;
  template <Type ... Values> using values = isPartitionedValue<Type, Operator, Values...>;
 };
}
#endif

