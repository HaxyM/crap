#ifndef CRAP_ALGORITHM_COUNTVALUE
#define CRAP_ALGORITHM_COUNTVALUE

#include "../functional/plusvalue.h"
namespace crap
{
 template <class Type, Type Value, template <Type, Type> class Operator, Type ... Values>
	 using countValue = plusValue<std :: size_t, ((Operator <Values, Value> :: value) ? 1u : 0u)...>;
}
#endif

