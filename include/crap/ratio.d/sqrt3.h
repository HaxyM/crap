#include <cstdint>
#include <type_traits>

#include "identity.h"
#include "invsqrt3.h"
#include "../numbers.d/sqrt3.h"

#ifndef CRAP_RATIO_SQRT3
#define CRAP_RATIO_SQRT3

namespace crap
{
#ifdef UINT8_C
 template <char Sign, std :: uint8_t Numerator, std :: uint8_t Denominator>
	 struct sqrt3<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(51), UINT8_C(29)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, std :: uint16_t Numerator, std :: uint16_t Denominator>
	 struct sqrt3<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(13107), UINT16_C(7567)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, std :: uint32_t Numerator, std :: uint32_t Denominator>
	 struct sqrt3<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(1431655765), UINT32_C(826566841)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, std :: uint64_t Numerator, std :: uint64_t Denominator>
	 struct sqrt3<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(6148914691236517205), UINT64_C(3550077552209447801)>;
 };
#endif

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct sqrt3<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using constInvSqrt3 = typename invSqrt3 <const1> :: type;
  public:
  using type = valueRatio<Type, constInvSqrt3 :: sign, constInvSqrt3 :: den, constInvSqrt3 :: num>;
 };
}
#endif

