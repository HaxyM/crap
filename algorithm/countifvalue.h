#ifndef CRAP_ALGORITHM_COUNTIFVALUE
#define CRAP_ALGORITHM_COUNTIFVALUE

#include "../functional/plusvalue.h"

namespace crap
{
 template <class Type, template <Type> class Operator, Type ... Values>
	 using countIfValue = plusValue<std :: size_t, ((Operator <Values> :: value) ? 1u : 0u)...>;
}
#endif

