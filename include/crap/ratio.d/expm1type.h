#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "abstype.h"
#include "dividestype.h"
#include "e.h"
#include "identity.h"
#include "lesstype.h"
#include "minustype.h"
#include "modftype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "zero.h"
#include "../cmath.d/expm1type.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_EXPM1TYPE
#define CRAP_RATIO_EXPM1TYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct expm1Type<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const0 = typename zero <passed> :: type;
  using decomposed = modfType<passed>;
  constexpr const static bool negative = lessType <passed, const0> :: value;
  using const1 = typename identity <passed> :: type;
  using natural = typename absType <typename decomposed :: intPart> :: type;
  using remainder = typename decomposed :: type;
  constexpr const static decltype(natural :: num) n = natural :: num;
  constexpr const static bool nEven = ((n % 2u) == 0u);
  //Natural power part
  template <std :: uintmax_t N, bool Even, class ... Empty> struct naturalPower;
  template <class ... Empty> struct naturalPower<UINTMAX_C(0), true, Empty...>;
  template <class ... Empty> struct naturalPower<UINTMAX_C(1), false, Empty...>;
  template <class ... Empty> struct naturalPower<UINTMAX_C(2), true, Empty...>;
  template <class ... Empty> struct naturalPower<UINTMAX_C(3), false, Empty...>;
  template <std :: uintmax_t N, class ... Empty> struct naturalPower<N, true, Empty...>;
  template <std :: uintmax_t N, class ... Empty> struct naturalPower<N, false, Empty...>;
  using naturalPowerPart = typename naturalPower <n, nEven> :: type;
  //<0, 1) power part
  template <class Sum, class Element, class Step, class Rem, bool isFinal>
	  struct remPower;
  template <class Sum, class Element, class Step, class Rem>
	  struct remPower<Sum, Element, Step, Rem, true>;
  template <class Sum, class Element, class Step, class Rem>
	  struct remPower<Sum, Element, Step, Rem, false>;
  constexpr const static typename naturalPowerPart :: valueType signedNatPowerPartNumerator =
	  (negative ? (naturalPowerPart :: den) : (naturalPowerPart :: num));
  constexpr const static typename naturalPowerPart :: valueType signedNatPowerPartDenominator =
	  (negative ? (naturalPowerPart :: num) : (naturalPowerPart :: den));
  using signedNatPowerPart = valueRatio<Type, '+', signedNatPowerPartNumerator, signedNatPowerPartDenominator>;
  using remPowerPart = typename remPower <const0, const1, const0, remainder, false> :: type;
  using withoutOffset = typename multipliesType <remPowerPart, signedNatPowerPart> :: type;
  using offset = typename minusType <signedNatPowerPart, const1> :: type;
  public:
  using type = typename plusType <withoutOffset, offset> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
 struct expm1Type <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<UINTMAX_C(0), true, Empty...>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename identity <passed> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
 struct expm1Type <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<UINTMAX_C(1), false, Empty...>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename e <passed> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
 struct expm1Type <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<UINTMAX_C(2), true, Empty...>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using constE = typename e <typename identity <passed> :: type> :: type;
  public:
  using type = typename multipliesType <constE, constE> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class ... Empty>
 struct expm1Type <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<UINTMAX_C(3), false, Empty...>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using constE = typename e <typename identity <passed> :: type> :: type;
  public:
  using type = typename multipliesType <constE, constE, constE> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <std :: uintmax_t N, class ... Empty>
 struct expm1Type <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<N, true, Empty...>
 {
  private:
  constexpr const static std :: uintmax_t nextN = N / UINTMAX_C(2);
  constexpr const static bool nextEven =
	  ((nextN % UINTMAX_C(2)) == UINTMAX_C(0));
  using nextType = typename naturalPower <nextN, nextEven> :: type;
  public:
  using type = typename multipliesType <nextType, nextType> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <std :: uintmax_t N, class ... Empty>
 struct expm1Type <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<N, false, Empty...>
 {
  private:
  constexpr const static std :: uintmax_t nextN =
	  (N - UINTMAX_C(1)) / UINTMAX_C(2);
  constexpr const static bool nextEven =
	  ((nextN % UINTMAX_C(2)) == UINTMAX_C(0));
  using nextType = typename naturalPower <nextN, nextEven> :: type;
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using constE = typename e <typename identity <passed> :: type> :: type;
  public:
  using type = typename multipliesType <constE, nextType, nextType> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class Sum, class Element, class Step, class Rem>
 struct expm1Type <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 remPower<Sum, Element, Step, Rem, true>
 {
  using type = Sum;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class Sum, class Element, class Step, class Rem>
 struct expm1Type <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 remPower<Sum, Element, Step, Rem, false>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using nextStep = typename plusType <Step, const1> :: type;
  using nextSubElement = typename dividesType <Rem, nextStep> :: type;
  using nextElement = typename multipliesType <Element, nextSubElement> :: type;
  using sum = typename plusType <Sum, nextElement> :: type;
  using cond = typename minusType <sum, Sum> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  public:
  using type = typename remPower <sum, nextElement, nextStep, Rem, nextFinal> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename expm1Type <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 expm1(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: expm1Type <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: expm1(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

