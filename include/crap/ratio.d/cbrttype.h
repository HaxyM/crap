#include <cstddef>
#include <type_traits>

#include "abstype.h"
#include "cbrt2.h"
#include "ceiltype.h"
#include "dividestype.h"
#include "equaltotype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "negatetype.h"
#include "plustype.h"
#include "valueratio.h"
#include "zero.h"
#include "../bit.d/bitfloorvalue.h"
#include "../bit.d/bitwidthvalue.h"
#include "../cmath.d/cbrttype.h"
#include "../functional.d/dividestype.h"
#include "../functional.d/minustype.h"
#include "../functional.d/multipliestype.h"
#include "../functional.d/plustype.h"
#include "../numbers.d/cbrt2.h"
#include "../numbers.d/identity.h"
#include "../numbers.d/zero.h"

#ifndef CRAP_RATIO_CBRTTYPE
#define CRAP_RATIO_CBRTTYPE

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct cbrtType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = typename absType <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  using ceil = typename ceilType <passed> :: type;
  constexpr const static std :: size_t bitWidth = bitWidthValue <decltype(ceil :: num), ceil :: num> :: value;
  template <class A, class C, std :: size_t bitWidth, bool isInital, bool isFinal> struct step;
  template <class A, class C, std :: size_t bitWidth> struct step<A, C, bitWidth, false, true>;
  template <class A, class C, std :: size_t bitWidth> struct step<A, C, bitWidth, true, false>;
  template <class A, class C> struct step<A, C, 0u, false, true>;
  template <class A, class C> struct step<A, C, 0u, true, false>;
  public:
  using type = typename step <passed, void, bitWidth, true, false> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class A, class C, std :: size_t bitWidth, bool isInitial, bool isFinal>
 struct cbrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: step
 {
  private:
  using const1 = typename identity <A> :: type;
  using const3 = typename plusType <const1, const1, const1> :: type;
  using thirdC = typename dividesType <C, const3> :: type;
  using C1 = typename plusType <const1, C> :: type;
  using C2 = typename minusType <const1, thirdC> :: type;
  using C3 = typename multipliesType <C1, C2, C2, C2> :: type;
  using nextC = typename minusType <C3, const1> :: type;
  using nextA = typename multipliesType <A, C2> :: type;
  using cond = typename minusType <A, nextA> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  public:
  using type = typename step <nextA, nextC, bitWidth, false, nextFinal> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class A, class C, std :: size_t bitWidth>
 struct cbrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, bitWidth, false, true>
 {
  private:
  using valueType = typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type;
  constexpr static valueType any = zero <valueType> :: value;
  constexpr static valueType zeros = any ^ any;
  constexpr static valueType ones = ~zeros;
  constexpr static valueType one = (~(ones << 1u)) & ones;
  constexpr static valueType scaleNum = (one << ((bitWidth - 1u) / 3u)) & ones;
  //FIXME: Export above computations to something generic.
  using scale = valueRatio<Type, Sign, scaleNum, identity <decltype(scaleNum)> :: value>;
  template <class Scale, std :: size_t> struct scaleUp;
  template <class Scale> struct scaleUp<Scale, 0u>;
  template <class Scale> struct scaleUp<Scale, 1u>;
  template <class Scale> struct scaleUp<Scale, 2u>;
  public:
  using type = typename scaleUp <scale, (bitWidth - 1u) % 3u> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class A, class C, std :: size_t bitWidth>
 struct cbrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, bitWidth, true, false>
 {
  private:
  using ceil = typename absType <typename ceilType <A> :: type> :: type;
  using scale = valueRatio<Type, '+', bitFloorValue <decltype(ceil :: num), ceil :: num> :: value, ceil :: den>;
  using properA = typename dividesType <A, scale> :: type;
  using sqrA = typename multipliesType <properA, properA> :: type;
  using properC = typename minusType <sqrA, typename identity <A> :: type> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(properC :: num), properC :: num, zero <decltype(properC :: num)> :: value> :: value;
  public:
  using type = typename step <properA, properC, bitWidth, false, nextFinal> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class A, class C>
 struct cbrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, 0u, false, true>
 {
  using type = typename std :: conditional <Sign == '+', A, typename negateType <A> :: type> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class A, class C>
 struct cbrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, 0u, true, false>
 {
  private:
  using sqrA = typename multipliesType <A, A> :: type;
  using properC = typename minusType <sqrA, typename identity <A> :: type> :: type;
  constexpr const static bool cFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(properC :: num), properC :: num, zero <decltype(properC :: num)> :: value> :: value;
  constexpr const static bool aFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(A :: num), A :: num, zero <decltype(A :: num)> :: value> :: value;
  public:
  using type = typename step <A, properC, 0u, false, (aFinal || cFinal)> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class A, class C, std :: size_t bitWidth>
	 template <class Scale>
 struct cbrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, bitWidth, false, true> :: template scaleUp<Scale, 0u>
 {
  using type = typename multipliesType <A, Scale> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class A, class C, std :: size_t bitWidth>
	 template <class Scale>
 struct cbrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, bitWidth, false, true> :: template scaleUp<Scale, 1u>
 {
  using type = typename multipliesType <A, Scale, typename cbrt2 <typename identity <A> :: type> :: type> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 template <class A, class C, std :: size_t bitWidth>
	 template <class Scale>
 struct cbrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, bitWidth, false, true> :: template scaleUp<Scale, 2u>
 {
  private:
  using constCbrt2 = typename cbrt2 <typename identity <A> :: type> :: type;
  public:
  using type = typename multipliesType <A, Scale, constCbrt2, constCbrt2> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename cbrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 cbrt(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: cbrtType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: cbrt(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

