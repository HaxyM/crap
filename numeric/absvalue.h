#ifndef CRAP_NUMERIC_ABSVALUE
#define CRAP_NUMERIC_ABSVALUE

#include <type_traits>

#include "zero.h"

namespace crap
{
 template <class Type, Type Value> using absValue =
	 std :: integral_constant<decltype((Value < zero <Type> :: value) ? -Value : Value),(Value < zero <Type> :: value) ? -Value : Value>;
}
#endif

