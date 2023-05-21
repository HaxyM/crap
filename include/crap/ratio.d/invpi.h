#include <cstdint>
#include <type_traits>

#include "identity.h"
#include "pi.h"
#include "../numbers.d/invpi.h"

#ifndef CRAP_RATIO_INVPI
#define CRAP_RATIO_INVPI

namespace crap
{
#ifdef UINT8_C
 template <char Sign, std :: uint8_t Numerator, std :: uint8_t Denominator>
	 struct invPi<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(27), UINT8_C(85)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, std :: uint16_t Numerator, std :: uint16_t Denominator>
	 struct invPi<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(7487), UINT16_C(23513)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, std :: uint32_t Numerator, std :: uint32_t Denominator>
	 struct invPi<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(981285313), UINT32_C(3082798721)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, std :: uint64_t Numerator, std :: uint64_t Denominator>
	 struct invPi<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(5871781006564002461), UINT64_C(18446744073709551615)>;
 };
#endif

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct invPi<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using constPi = typename pi <const1> :: type;
  public:
  using type = valueRatio<Type, constPi :: sign, constPi :: den, constPi :: num>;
 };
}
#endif

