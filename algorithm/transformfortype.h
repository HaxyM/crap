#ifndef CRAP_ALGORITHM_TRANSFORMFORTYPE
#define CRAP_ALGORITHM_TRANSFORMFORTYPE

#include "transformvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator> struct transformForType
 {
  template <Type ... Values> using type = transformValue<Type, Operator, Values...>;
  template <Type ... Values> using values = transformValue<Type, Operator, Values...>;
 };
}
#endif

