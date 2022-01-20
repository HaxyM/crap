#ifndef CRAP_ALGORITHM_FILLVALUE
#define CRAP_ALGORITHM_FILLVALUE

#include "copyvalue.h"

namespace crap
{
 template <class Type, Type Value, Type ... Values> using fillValue = copyValue<Type, (Values, Value)...>;
}
#endif

