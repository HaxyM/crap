#ifndef CRAP_CMATH_RATIOSQRT1_2
#define CRAP_CMATH_RATIOSQRT1_2

#include "sqrttype.h"

#include <cstddef>
#include <ratio>

namespace crap
{
 template <std :: size_t Steps = 5u> using ratioSqrt1_2 = sqrtType<std :: ratio<1, 2>, Steps>;
 template <std :: size_t Steps = 5u> using ratioSqrt1_2_t = typename ratioSqrt1_2 <Steps> :: type;
}
#endif

