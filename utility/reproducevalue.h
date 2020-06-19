#ifndef CRAP_UTILITY_REPRODUCEVALUE
#define CRAP_UTILITY_REPRODUCEVALUE

#include "../algorithm/fillfortype.h"
#include "../numeric/iotavalue.h"

namespace crap
{
 template <std :: size_t N, class Type, Type Value>
	 using reproduceValue = typename iotaValue <N, Type> :: template
	 type<fillForType <Type, Value> :: template type>;
}
#endif

