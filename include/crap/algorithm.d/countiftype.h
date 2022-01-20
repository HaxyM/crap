#ifndef CRAP_ALGORITHM_COUNTIFTYPE
#define CRAP_ALGORITHM_COUNTIFTYPE

#include "../functional.d/plusvalue.h"

namespace crap
{
 template <template <class> class Operator, class ... Types>
	 using countIfType = plusValue<std :: size_t, ((Operator <Types> :: value) ? 1u : 0u)...>;
}
#endif

