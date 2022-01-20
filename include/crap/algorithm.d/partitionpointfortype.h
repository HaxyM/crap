#ifndef CRAP_ALGORITHM_PARTITIONPOINTFORTYPE
#define CRAP_ALGORITHM_PARTITIONPOINTFORTYPE

#include "partitionpointvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator> struct partitionPointForType
 {
  template <Type ... Values> using type = partitionPointValue<Type, Operator, Values...>;
  template <Type ... Values> using values = partitionPointValue<Type, Operator, Values...>;
 };
}
#endif

