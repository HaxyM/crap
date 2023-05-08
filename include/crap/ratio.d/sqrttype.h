#include <cstddef>
#include <type_traits>

#include "ceiltype.h"
#include "dividestype.h"
#include "equaltotype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "sqrt2.h"
#include "valueratio.h"
#include "zero.h"
#include "../bit.d/bitfloorvalue.h"
#include "../bit.d/bitwidthvalue.h"
#include "../cmath.d/sqrttype.h"
#include "../functional.d/dividestype.h"
#include "../functional.d/minustype.h"
#include "../functional.d/multipliestype.h"
#include "../functional.d/plustype.h"
#include "../numbers.d/identity.h"
#include "../numbers.d/sqrt2.h"
#include "../numbers.d/zero.h"

#ifndef CRAP_RATIO_SQRTTYPE
#define CRAP_RATIO_SQRTTYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct sqrtType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  static_assert(Sign == '+', "Value must be positive.");
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
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

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class C, std :: size_t bitWidth, bool isInitial, bool isFinal>
 struct sqrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: step
 {
  private:
  using const2 = typename plusType <typename identity <A> :: type, typename identity <A> :: type> :: type;
  using const3 = typename plusType <const2, typename identity <A> :: type> :: type;
  using const4 = typename plusType <const2, const2> :: type;
  using AC = typename multipliesType <A, C> :: type;
  using halfAC = typename dividesType <AC, const2> :: type;
  using nextA = typename minusType <A, halfAC> :: type;
  using Cless3 = typename minusType <C, const3> :: type;
  using Cs = typename multipliesType <C, C, Cless3> :: type;
  using nextC = typename dividesType <Cs, const4> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(nextC :: num), nextC :: num, zero <decltype(nextC :: num)> :: value> :: value;
  public:
  using type = typename step <nextA, nextC, bitWidth, false, nextFinal> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class C, std :: size_t bitWidth>
 struct sqrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, bitWidth, false, true>
 {
  private:
  using valueType = typename std :: add_const <Type> :: type;
  constexpr static valueType any = zero <valueType> :: value;
  constexpr static valueType zeros = any ^ any;
  constexpr static valueType ones = ~zeros;
  constexpr static valueType one = (~(ones << 1u)) & ones;
  constexpr static valueType scaleNum = (one << ((bitWidth - 1u) / 2u)) & ones;
  //FIXME: Export above computations to something generic.
  using scale = valueRatio<Type, '+', scaleNum, identity <decltype(scaleNum)> :: value>;
  template <class Scale, bool oddPower> struct scaleUp;
  template <class Scale> struct scaleUp<Scale, false>;
  public:
  using type = typename scaleUp <scale, (((bitWidth - 1u) % 2u) != 0u)> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class C, std :: size_t bitWidth>
 struct sqrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, bitWidth, true, false>
 {
  private:
  using ceil = typename ceilType <A> :: type;
  using scale = valueRatio<Type, '+', bitFloorValue <decltype(ceil :: num), ceil :: num> :: value, ceil :: den>;
  using properA = typename dividesType <A, scale> :: type;
  using properC = typename minusType <properA, typename identity <A> :: type> :: type;
  constexpr const static bool nextFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(properC :: num), properC :: num, zero <decltype(properC :: num)> :: value> :: value;
  public:
  using type = typename step <properA, properC, bitWidth, false, nextFinal> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class C>
 struct sqrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, 0u, false, true>
 {
  using type = A;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class C>
 struct sqrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, 0u, true, false>
 {
  private:
  using properC = typename minusType <A, typename identity <A> :: type> :: type;
  constexpr const static bool cFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(properC :: num), properC :: num, zero <decltype(properC :: num)> :: value> :: value;
  constexpr const static bool aFinal = //FIXME: Add check if is zero.
	  equalToValue <decltype(A :: num), A :: num, zero <decltype(A :: num)> :: value> :: value;
  public:
  using type = typename step <A, properC, 0u, false, (aFinal || cFinal)> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class C, std :: size_t bitWidth>
	 template <class Scale, bool oddPower>
 struct sqrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, bitWidth, false, true> :: scaleUp
 {
  using type = typename multipliesType <A, Scale, typename sqrt2 <typename identity <A> :: type> :: type> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class A, class C, std :: size_t bitWidth>
	 template <class Scale>
 struct sqrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 step<A, C, bitWidth, false, true> :: template scaleUp<Scale, false>
 {
  using type = typename multipliesType <A, Scale> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename sqrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 sqrt(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: sqrtType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: sqrt(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

