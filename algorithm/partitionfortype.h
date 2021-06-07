#ifndef CRAP_ALGORITHM_PARTITIONFORTYPE
#define CRAP_ALGORITHM_PARTITIONFORTYPE

#include "partitionvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator> struct partitionForType
 {
  template <Type ... Values> using type = partitionValue<Type, Operator, Values...>;
  template <Type ... Values> using values = partitionValue<Type, Operator, Values...>;
 };
}
#endif

