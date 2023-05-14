#include <cstdint>
#include <type_traits>

#include "identity.h"
#include "ln2.h"
#include "../numbers.d/log2e.h"

#ifndef CRAP_RATIO_LOG2E
#define CRAP_RATIO_LOG2E

namespace crap
{
#ifdef UINT8_C
 template <char Sign, std :: uint8_t Numerator, std :: uint8_t Denominator>
	 struct log2e<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(127), UINT8_C(91)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, std :: uint16_t Numerator, std :: uint16_t Denominator>
	 struct log2e<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(4681), UINT16_C(3246)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, std :: uint32_t Numerator, std :: uint32_t Denominator>
	 struct log2e<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(1431655765), UINT32_C(992348169)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, std :: uint64_t Numerator, std :: uint64_t Denominator>
	 struct log2e<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(18446744073709551615), UINT64_C(12786308645202655981)>;
 };
#endif

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct log2e<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using constLn2 = typename ln2 <const1> :: type;
  public:
  using type = valueRatio<Type, constLn2 :: sign, constLn2 :: den, constLn2 :: num>;
 };
}
#endif

