#ifndef CRAP_CMATH_RATIOSQRT2
#define CRAP_CMATH_RATIOSQRT2

#include "sqrttype.h"

#include <cstddef>
#include <ratio>

namespace crap
{
 template <std :: size_t Steps = 5u> using ratioSqrt2 = sqrtType<std :: ratio<2, 1>, Steps>;
 template <std :: size_t Steps = 5u> using ratioSqrt2_t = typename ratioSqrt2 <Steps> :: type;
}
#endif

