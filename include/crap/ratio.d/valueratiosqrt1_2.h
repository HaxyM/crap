#ifndef CRAP_RATIO_VALUERATIOSQRT1_2
#define CRAP_RATIO_VALUERATIOSQRT1_2

#include "sqrttype.h"
#include "valueratio.h"
#include "../numeric.d/identity.h"

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <class Type, std :: size_t Steps = 5u>
	 using valueRatioSqrt1_2 = sqrtType<valueRatio<Type, '+', identity <typename std :: make_unsigned <Type> :: type> :: value, identity <typename std :: make_unsigned <Type> :: type> :: value + identity <typename std :: make_unsigned <Type> :: type> :: value>, Steps>;
 template <class Type, std :: size_t Steps = 5u>
	 using valueRatioSqrt1_2_t = typename valueRatioSqrt1_2 <Type, Steps> :: type;
}
#endif

