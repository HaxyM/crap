#include <cstddef>
#include <cstdint>
#include <type_traits>

#include "abstype.h"
#include "dividestype.h"
#include "e.h"
#include "floortype.h"
#include "identity.h"
#include "lesstype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "zero.h"
#include "../cmath.d/exptype.h"
#include "../functional.d/equaltovalue.h"

#ifndef CRAP_RATIO_EXPTYPE
#define CRAP_RATIO_EXPTYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct expType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const0 = typename zero <passed> :: type;
  constexpr const static bool negative = lessType <passed, const0> :: value;
  using abs = typename absType <passed> :: type;
  using const1 = typename identity <passed> :: type;
  using constE = typename e <const1> :: type;
  using natural = typename floorType <abs> :: type;
  using remainder = typename minusType <abs, natural> :: type;
  constexpr const static decltype(natural :: num) n = natural :: num;
  constexpr const static bool nEven = ((n % 2u) == 0u);
  //Natural power part
  template <class AnyType, std :: uintmax_t N, bool Even> struct naturalPower;
  template <class AnyType> struct naturalPower<AnyType, UINTMAX_C(0), true>;
  template <class AnyType> struct naturalPower<AnyType, UINTMAX_C(1), false>;
  template <class AnyType> struct naturalPower<AnyType, UINTMAX_C(2), true>;
  template <class AnyType> struct naturalPower<AnyType, UINTMAX_C(3), false>;
  template <class AnyType, std :: uintmax_t N> struct naturalPower<AnyType, N, true>;
  template <class AnyType, std :: uintmax_t N> struct naturalPower<AnyType, N, false>;
  using naturalPowerPart = typename naturalPower <const1, n, nEven> :: type;
  //<0, 1) power part
  template <class Sum, class Element, class Step, class Rem, bool isFinal>
	  struct remPower;
  template <class Sum, class Element, class Step, class Rem>
	  struct remPower<Sum, Element, Step, Rem, true>;
  template <class Sum, class Element, class Step, class Rem>
	  struct remPower<Sum, Element, Step, Rem, false>;
  using remPowerPart = typename remPower <const1, const1, const0, remainder, false> :: type;
  using powerOfAbs = typename multipliesType <remPowerPart, naturalPowerPart> :: type;
  constexpr const static typename powerOfAbs :: valueType numerator =
	  (negative ? (powerOfAbs :: den) : (powerOfAbs :: num));
  constexpr const static typename powerOfAbs :: valueType denominator =
	  (negative ? (powerOfAbs :: num) : (powerOfAbs :: den));
  public:
  using type = valueRatio<Type, '+', numerator, denominator>;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class AnyType>
 struct expType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<AnyType, UINTMAX_C(0), true>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename identity <passed> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class AnyType>
 struct expType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<AnyType, UINTMAX_C(1), false>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename e <passed> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class AnyType>
 struct expType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<AnyType, UINTMAX_C(2), true>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using constE = typename e <typename identity <passed> :: type> :: type;
  public:
  using type = typename multipliesType <constE, constE> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class AnyType>
 struct expType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<AnyType, UINTMAX_C(3), false>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using constE = typename e <typename identity <passed> :: type> :: type;
  public:
  using type = typename multipliesType <constE, constE, constE> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class AnyType, std :: uintmax_t N>
 struct expType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<AnyType, N, true>
 {
  private:
  constexpr const static std :: uintmax_t nextN = N / UINTMAX_C(2);
  constexpr const static bool nextEven =
	  ((nextN % UINTMAX_C(2)) == UINTMAX_C(0));
  using nextType = typename naturalPower <AnyType, nextN, nextEven> :: type;
  public:
  using type = typename multipliesType <nextType, nextType> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class AnyType, std :: uintmax_t N>
 struct expType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 naturalPower<AnyType, N, false>
 {
  private:
  constexpr const static std :: uintmax_t nextN =
	  (N - UINTMAX_C(1)) / UINTMAX_C(2);
  constexpr const static bool nextEven =
	  ((nextN % UINTMAX_C(2)) == UINTMAX_C(0));
  using nextType = typename naturalPower <AnyType, nextN, nextEven> :: type;
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using constE = typename e <typename identity <passed> :: type> :: type;
  public:
  using type = typename multipliesType <constE, nextType, nextType> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class Sum, class Element, class Step, class Rem>
 struct expType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 remPower<Sum, Element, Step, Rem, true>
 {
  using type = Sum;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class Sum, class Element, class Step, class Rem>
 struct expType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
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
	 constexpr typename expType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 exp(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: expType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: exp(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

