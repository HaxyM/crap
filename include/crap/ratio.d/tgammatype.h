#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>

#include "ceiltype.h"
#include "dividestype.h"
#include "e.h"
#include "exptype.h"
#include "floortype.h"
#include "lesstype.h"
#include "ln10.h"
#include "log2e.h"
#include "minustype.h"
#include "multipliestype.h"
#include "negatetype.h"
#include "pi.h"
#include "plustype.h"
#include "powtype.h"
#include "sqrttype.h"
#include "valueratio.h"
#include "zero.h"
#include "../bit.d/bitwidthvalue.h"
#include "../cmath.d/tgammatype.h"
#include "../functional.d/equaltovalue.h"
#include "../functional.d/lessvalue.h"
#include "../numbers.d/identity.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/iotavalue.h"
#include "../utility.d/reproducetype.h"

#ifndef CRAP_RATIO_TGAMMATYPE
#define CRAP_RATIO_TGAMMATYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct tgammaType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using integralPart = typename floorType <passed> :: type;
  using fracPart = typename minusType <passed, integralPart> :: type;
  using const0 = typename zero <passed> :: type;
  constexpr const static bool isIntegral = //FIXME: Add check if is zero.
	  equalToValue <decltype(fracPart :: num), fracPart :: num, zero <decltype(fracPart :: num)> :: value> :: value;
  constexpr const static bool positive = lessType <const0, passed> :: value;
  static_assert(positive || !isIntegral, "Value out of range.");
  template <bool isIntegral, class integralPart, class fracPart> struct simpleFactorial;
  template <class integralPart, class fracPart> struct simpleFactorial<true, integralPart, fracPart>;
  template <class integralPart, class fracPart> struct simpleFactorial<false, integralPart, fracPart>;
  public:
  using type = typename simpleFactorial <isIntegral, integralPart, fracPart> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class integralPart, class fracPart>
 struct tgammaType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 simpleFactorial<true, integralPart, fracPart>
 {
  private:
  template <bool moreOne, class ... Empty> struct Implementation;
  template <class ... Empty> struct Implementation<true, Empty...>;
  template <class ... Empty> struct Implementation<false, Empty...>;
  constexpr const static bool moreOne = lessType <typename identity <integralPart> :: type, integralPart> :: value;
  public:
  using type = typename Implementation <moreOne> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class integralPart, class fracPart>
 struct tgammaType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 simpleFactorial<false, integralPart, fracPart>
 {
  private:
  template <bool negative, bool positive, class ... Empty> struct factorialPart;
  template <class ... Empty> struct factorialPart<true, false, Empty...>;
  template <class ... Empty> struct factorialPart<false, true, Empty...>;
  template <class ... Empty> struct factorialPart<false, false, Empty...>;
  template <Type K, class Sum, class Param, Type A, bool isFinal> struct SpougesPart;
  template <Type K, class Sum, class Param, Type A> struct SpougesPart<K, Sum, Param, A, true>;
  template <Type K, class Sum, class Param, Type A> struct SpougesPart<K, Sum, Param, A, false>;
  using const0 = typename zero <integralPart> :: type;
  using const1 = typename identity <fracPart> :: type;
  using constPi = typename pi <const1> :: type;
  using constTau = typename plusType <constPi, constPi> :: type;
  //Estimation of c0
  using initialSum = typename sqrtType <constTau> :: type;
  //Estimation of A param
  constexpr const static Type constMaxPow2 = bitWidthValue <Type, std :: numeric_limits <Type> :: max()> :: value;
  using maxPow2R = valueRatio<Type, '+', constMaxPow2, identity <Type> :: value>;
  using constMaxOrder = typename ceilType <typename dividesType <maxPow2R, typename log2e <const1> :: type, typename ln10 <const1> :: type> :: type> :: type;
  constexpr const static Type initialA = constMaxOrder :: num;
  //Initial value of K param
  constexpr const static Type initialK = identity <Type> :: value;
  //Initial value of Param param
  using constEtoA = typename reproduceType <initialA, typename e <const1> :: type> :: template
	  type <multipliesType> :: type;
  using initialParam = typename negateType <constEtoA> :: type;
  //Initial value of isFinal param
  constexpr const static bool initialIsFinal = !(lessValue <Type, initialK, initialA> :: value);

  constexpr const static bool integralNegative = lessType <integralPart, const0> :: value;
  constexpr const static bool integralPositive = lessType <const0, integralPart> :: value;
  using factorialPartResult = typename factorialPart <integralNegative, integralPositive> :: type;
  using SpougesPartResult =
	  typename SpougesPart <initialK, initialSum, initialParam, initialA, initialIsFinal> :: type;
  public:
  using type = typename multipliesType <factorialPartResult, SpougesPartResult> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class integralPart, class fracPart>
	 template <class ... Empty>
 struct tgammaType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 simpleFactorial <true, integralPart, fracPart> :: template
	 Implementation<true, Empty...>
 {
  private:
  template <Type Num> using makeRatio = valueRatio<Type, '+', Num, identity <Type> :: value>;
  template <Type ... Nums> using product = typename multipliesType <makeRatio<Nums>...> :: type;
  public:
  using type = typename iotaValue <(integralPart :: num - 1u), Type, identity <Type> :: value> :: template
	  type<product>;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class integralPart, class fracPart>
	 template <class ... Empty>
 struct tgammaType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 simpleFactorial <true, integralPart, fracPart> :: template
	 Implementation<false, Empty...>
 {
  using type = typename identity <integralPart> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class integralPart, class fracPart>
	 template <class ... Empty>
 struct tgammaType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 simpleFactorial <false, integralPart, fracPart> :: template
	 factorialPart<true, false, Empty...>
 {
  private:
  template <Type Num> using makeRatio = valueRatio<Type, '+', Num, identity <Type> :: value>;
  template <Type Num> using makeElement = typename minusType <fracPart, makeRatio<Num> > :: type;
  template <Type Num> using invertedElement =
	  valueRatio<Type, makeElement <Num> :: sign, makeElement <Num> :: den, makeElement <Num> :: num>;
  template <Type ... Nums> using product = typename multipliesType <invertedElement<Nums>...> :: type;
  public:
  using type = typename iotaValue <integralPart :: num, Type, identity <Type> :: value> :: template
	  type<product>;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class integralPart, class fracPart>
	 template <class ... Empty>
 struct tgammaType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 simpleFactorial <false, integralPart, fracPart> :: template
	 factorialPart<false, true, Empty...>
 {
  private:
  template <Type Num> using makeRatio = valueRatio<Type, '+', Num, identity <Type> :: value>;
  template <Type Num> using makeElement = typename plusType <fracPart, makeRatio<Num> > :: type;
  template <Type ... Nums> using product = typename multipliesType <makeElement<Nums>...> :: type;
  public:
  using type = typename iotaValue <integralPart :: num, Type, zero <Type> :: value> :: template
	  type<product>;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class integralPart, class fracPart>
	 template <class ... Empty>
 struct tgammaType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 simpleFactorial <false, integralPart, fracPart> :: template
	 factorialPart<false, false, Empty...>
 {
  using type = typename identity <integralPart> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class integralPart, class fracPart>
	 template <Type K, class Sum, class Param, Type A>
 struct tgammaType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 simpleFactorial <false, integralPart, fracPart> :: template
	 SpougesPart<K, Sum, Param, A, true>
 {
  private:
  using const1 = typename identity <fracPart> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using z = typename minusType <fracPart, const1> :: type;
  using constHalf = typename dividesType <const1, const2> :: type;
  using constA = valueRatio<decltype(A), '+', A, identity <decltype(A)> :: value>;
  using zPlusA = typename plusType <z, constA> :: type;
  using param1 = typename powType <zPlusA, typename plusType <z, constHalf> :: type> :: type;
  using param2 = typename expType <typename negateType <zPlusA> :: type> :: type;
  public:
  using type = typename multipliesType <param1, param2, Sum> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class integralPart, class fracPart>
	 template <Type K, class Sum, class Param, Type A>
 struct tgammaType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 simpleFactorial <false, integralPart, fracPart> :: template
	 SpougesPart<K, Sum, Param, A, false>
 {
  private:
  using const1 = typename identity <fracPart> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using z = typename minusType <fracPart, const1> :: type;
  using constHalf = typename dividesType <const1, const2> :: type;
  using constE = typename e <const1> :: type;
  constexpr const static bool firstStep = equalToValue <decltype(K), K, identity <decltype(K)> :: value> :: value;
  //Nexp Param computation
  using constKforParam = valueRatio<decltype(K), '-', (firstStep ? identity <decltype(K)> :: value : (K - identity <decltype(K)> :: value)), identity <decltype(K)> :: value>;
  using nextParam = typename dividesType <Param, constKforParam, constE> :: type;
  //Next Sum computation
  using constK = valueRatio<decltype(K), '+', K, identity <decltype(K)> :: value>;
  using base = valueRatio<decltype(A - K), '+', (A - K), identity <decltype(A - K)> :: value>;
  using exponent = typename minusType <constK, constHalf> :: type;
  using cK = typename multipliesType <nextParam, typename powType <base, exponent> :: type> :: type;
  using sumStep = typename dividesType <cK, typename plusType <z, constK> :: type> :: type;
  using nextSum = typename plusType <Sum, sumStep> :: type;
  //Next K component
  constexpr const static Type nextK = K + identity <decltype(K)> :: value;
  //Next isFinal component
  constexpr const static bool nextIsFinal = !(lessValue <Type, K, A> :: value);
  public:
  using type = typename SpougesPart <nextK, nextSum, nextParam, A, nextIsFinal> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename tgammaType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 tgamma(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: tgammaType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: tgamma(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

