#include <cstdint>
#include <type_traits>

#include "identity.h"
#include "ln10.h"
#include "../numbers.d/log10e.h"

#ifndef CRAP_RATIO_LOG10E
#define CRAP_RATIO_LOG10E

namespace crap
{
#ifdef UINT8_C
 template <char Sign, std :: uint8_t Numerator, std :: uint8_t Denominator>
	 struct log10e<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(106), UINT8_C(255)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, std :: uint16_t Numerator, std :: uint16_t Denominator>
	 struct log10e<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(5690), UINT16_C(13107)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, std :: uint32_t Numerator, std :: uint32_t Denominator>
	 struct log10e<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(1865280574), UINT32_C(4294967295)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, std :: uint64_t Numerator, std :: uint64_t Denominator>
	 struct log10e<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(4005659580146785282), UINT64_C(9223372036854775807)>;
 };
#endif

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct log10e<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using constLn10 = typename ln10 <const1> :: type;
  public:
  using type = valueRatio<Type, constLn10 :: sign, constLn10 :: den, constLn10 :: num>;
 };
}
#endif

