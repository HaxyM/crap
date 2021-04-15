#ifndef CRAP_ALGORITHM_COUNTTYPE
#define CRAP_ALGORITHM_COUNTTYPE

#include "../functional/plusvalue.h"
namespace crap
{
 template <class Type, template <class, class> class Operator, class ... Types>
	 using countType = plusValue<std :: size_t, ((Operator <Types, Type> :: value) ? 1u : 0u)...>;
}
#endif

