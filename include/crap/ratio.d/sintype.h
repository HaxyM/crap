#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "abstype.h"
#include "dividestype.h"
#include "floortype.h"
#include "identity.h"
#include "lesstype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "negatetype.h"
#include "pi.h"
#include "plustype.h"
#include "valueratio.h"
#include "zero.h"
#include "../cmath.d/sintype.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_SINTYPE
#define CRAP_RATIO_SINTYPE

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct sinType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = typename absType <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  using const1 = typename identity <passed> :: type;
  using constPi = typename pi <const1> :: type;
  using constTau = typename plusType <constPi, constPi> :: type;
  using periods = typename dividesType <passed, constTau> :: type;
  using wholePeriods = typename floorType <periods> :: type;
  using shift = typename multipliesType <constTau, wholePeriods> :: type;
  using x = typename minusType <passed, shift> :: type;
  using initialSum = x;
  using initialElement = x;
  using initialArgument = typename negateType <typename multipliesType <x, x> :: type> :: type;
  using initialStep = typename identity <passed> :: type;
  template <class Sum, class Element, class Argument, class Step, bool isFinal> struct step;
  template <class Sum, class Element, class Argument, class Step> struct step<Sum, Element, Argument, Step, true>;
  public:
  using type = typename step <initialSum, initialElement, initialArgument, initialStep, false> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class Sum, class Element, class Argument, class Step, bool isFinal>
	 struct sinType<valueRatio<Type, Sign, Numerator, Denominator> > :: step
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using newNumerator = typename multipliesType <Element, Argument> :: type;
  using const1 = typename identity <passed> :: type;
  using nextStep1 = typename plusType <Step, const1> :: type;
  using nextElement1 = typename dividesType <newNumerator, nextStep1> :: type;
  using nextStep = typename plusType <nextStep1, const1> :: type;
  using nextElement = typename dividesType <nextElement1, nextStep> :: type;
  using sum = typename plusType <Sum, nextElement> :: type;
  using cond = typename minusType <sum, Sum> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  public:
  using type = typename step <sum, nextElement, Argument, nextStep, nextFinal> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class Sum, class Element, class Argument, class Step>
 struct sinType<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<Sum, Element, Argument, Step, true>
 {
  private:
  using const1 = typename identity <Sum> :: type;
  using absSum = typename absType <Sum> :: type;
  constexpr const static bool inRange = lessType <absSum, const1> :: value;
  constexpr const static char newSign =
	  (Sign == '-') ? ((Sum :: sign == '-') ? '+' : '-') : (Sum :: sign);
  using clamped = typename std :: conditional <inRange, Sum, const1> :: type;
  public:
  using type = valueRatio<Type, newSign, clamped :: num, clamped :: den>;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename sinType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 sin(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: sinType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: sin(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

