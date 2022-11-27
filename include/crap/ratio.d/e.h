#include <cstdint>
#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "minustype.h"
#include "plustype.h"
#include "valueratio.h"
#include "zero.h"
#include "../numbers.d/e.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_E
#define CRAP_RATIO_E

namespace crap
{
#ifdef UINT8_C
 template <char Sign, typename std :: make_unsigned <std :: int8_t> :: type Numerator, typename std :: make_unsigned <std :: int8_t> :: type Denominator>
	 struct e<valueRatio<std :: int8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int8_t, '+', UINT8_C(255), UINT8_C(94)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint8_t> :: type Numerator, typename std :: make_unsigned <std :: uint8_t> :: type Denominator>
	 struct e<valueRatio<std :: uint8_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint8_t, '+', UINT8_C(255), UINT8_C(94)>;
 };
#endif

#ifdef UINT16_C
 template <char Sign, typename std :: make_unsigned <std :: int16_t> :: type Numerator, typename std :: make_unsigned <std :: int16_t> :: type Denominator>
	 struct e<valueRatio<std :: int16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int16_t, '+', UINT16_C(65535), UINT16_C(24109)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint16_t> :: type Numerator, typename std :: make_unsigned <std :: uint16_t> :: type Denominator>
	 struct e<valueRatio<std :: uint16_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint16_t, '+', UINT16_C(65535), UINT16_C(24109)>;
 };
#endif

#ifdef UINT32_C
 template <char Sign, typename std :: make_unsigned <std :: int32_t> :: type Numerator, typename std :: make_unsigned <std :: int32_t> :: type Denominator>
	 struct e<valueRatio<std :: int32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int32_t, '+', UINT32_C(260412269), UINT32_C(95800320)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint32_t> :: type Numerator, typename std :: make_unsigned <std :: uint32_t> :: type Denominator>
	 struct e<valueRatio<std :: uint32_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint32_t, '+', UINT32_C(260412269), UINT32_C(95800320)>;
 };
#endif

#ifdef UINT64_C
 template <char Sign, typename std :: make_unsigned <std :: int64_t> :: type Numerator, typename std :: make_unsigned <std :: int64_t> :: type Denominator>
	 struct e<valueRatio<std :: int64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: int64_t, '+', UINT64_C(6613313319248080001), UINT64_C(2432902008176640000)>;
 };

 template <char Sign, typename std :: make_unsigned <std :: uint64_t> :: type Numerator, typename std :: make_unsigned <std :: uint64_t> :: type Denominator>
	 struct e<valueRatio<std :: uint64_t, Sign, Numerator, Denominator> >
 {
  using type = valueRatio<std :: uint64_t, '+', UINT64_C(6613313319248080001), UINT64_C(2432902008176640000)>;
 };
#endif

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct e<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using initialSum = typename identity <passed> :: type;
  using initialElement = typename identity <passed> :: type;
  using initialStep = typename zero <passed> :: type;
  template <class Sum, class Element, class Step, bool isFinal> struct step;
  template <class Sum, class Element, class Step> struct step<Sum, Element, Step, true>;
  public:
  using type = typename step <initialSum, initialElement, initialStep, false> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class Sum, class Element, class Step, bool isFinal>
	 struct e<valueRatio<Type, Sign, Numerator, Denominator> > :: step
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using nextStep = typename plusType <Step, const1> :: type;
  using nextElement = typename dividesType <Element, nextStep> :: type;
  using sum = typename plusType <Sum, nextElement> :: type;
  using cond = typename minusType <sum, Sum> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  public:
  using type = typename step <sum, nextElement, nextStep, nextFinal> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class Sum, class Element, class Step>
	 struct e<valueRatio<Type, Sign, Numerator, Denominator> > :: template step<Sum, Element, Step, true>
 {
  using type = Sum;
 };
}
#endif

