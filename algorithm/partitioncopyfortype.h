#ifndef CRAP_ALGORITHM_PARTITIONCOPYFORTYPE
#define CRAP_ALGORITHM_PARTITIONCOPYFORTYPE

#include "partitioncopyvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator> struct partitionCopyForType
 {
  template <Type ... Values> using type = partitionCopyValue<Type, Operator, Values...>;
  template <Type ... Values> using values = partitionCopyValue<Type, Operator, Values...>;
 };
}
#endif

