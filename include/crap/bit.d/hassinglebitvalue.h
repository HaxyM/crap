#ifndef CRAP_BIT_HASSINGLEBITVALUE
#define CRAP_BIT_HASSINGLEBITVALUE

#include "popcountvalue.h"
#include <type_traits>

namespace crap
{
 template <class Type, Type Value>
	 using hasSingleBitValue = std :: integral_constant<bool, popcountValue <Type, Value> :: value == 1u>;
}
#endif
