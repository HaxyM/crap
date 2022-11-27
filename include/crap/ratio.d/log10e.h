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
 template <char Sign, typename std :: make_unsigned <std :: int8_t> :: type Numerator, typename std :: make_unsigned <std :: int8_t> :: type Denominator>
	 struct log10e<valueRatio<std :: int8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int8_t, '+', UINT8_C(106), UINT8_C(255)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint8_t> :: type Numerator, typename std :: make_unsigned <std :: uint8_t> :: type Denominator>
	 struct log10e<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(106), UINT8_C(255)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, typename std :: make_unsigned <std :: int16_t> :: type Numerator, typename std :: make_unsigned <std :: int16_t> :: type Denominator>
	 struct log10e<valueRatio<std :: int16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int16_t, '+', UINT16_C(5690), UINT16_C(13107)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint16_t> :: type Numerator, typename std :: make_unsigned <std :: uint16_t> :: type Denominator>
	 struct log10e<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(5690), UINT16_C(13107)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, typename std :: make_unsigned <std :: int32_t> :: type Numerator, typename std :: make_unsigned <std :: int32_t> :: type Denominator>
	 struct log10e<valueRatio<std :: int32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int32_t, '+', UINT32_C(1865280574), UINT32_C(4294967295)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint32_t> :: type Numerator, typename std :: make_unsigned <std :: uint32_t> :: type Denominator>
	 struct log10e<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(1865280574), UINT32_C(4294967295)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, typename std :: make_unsigned <std :: int64_t> :: type Numerator, typename std :: make_unsigned <std :: int64_t> :: type Denominator>
	 struct log10e<valueRatio<std :: int64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int64_t, '+', UINT64_C(4005659580146785282), UINT64_C(9223372036854775807)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint64_t> :: type Numerator, typename std :: make_unsigned <std :: uint64_t> :: type Denominator>
	 struct log10e<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(4005659580146785282), UINT64_C(9223372036854775807)>;
 };
#endif

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
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

