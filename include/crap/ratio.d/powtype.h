#include <cstdint>
#include <type_traits>

#include "exptype.h"
#include "floortype.h"
#include "identity.h"
#include "logtype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "valueratio.h"
#include "zero.h"
#include "../cmath.d/powtype.h"
#include "../functional.d/equaltovalue.h"
#include "../functional.d/lessvalue.h"
#include "../functional.d/negatevalue.h"
#include "../functional.d/plusvalue.h"

#ifndef CRAP_RATIO_POWTYPE
#define CRAP_RATIO_POWTYPE

namespace crap
{
 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> >
 {
  private:
  template <bool isExponentIntegral, class...> struct integralExponent;
  template <class ... Empty> struct integralExponent<true, Empty...>;
  template <class ... Empty> struct integralExponent<false, Empty...>;
  using y = valueRatio<Type, SignY, NumeratorY, DenominatorY>;
  using cond = typename minusType <y, typename floorType<y> :: type> :: type;
  constexpr const static bool isExponentIntegral = //FIXME: Add check if is zero.
	  equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  static_assert((SignX == '+') || isExponentIntegral, "Value out of range.");
  public:
  using type = typename integralExponent <isExponentIntegral> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <class ... Empty>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 integralExponent<true, Empty...>
 {
  private:
  using valueType = typename std :: add_const <Type> :: type;
  using y = typename floorType <valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: type;
  template <class X, std :: uintmax_t Y, bool isEven> struct naturalPower;
  template <class X> struct naturalPower <X, UINTMAX_C(0), true>;
  template <class X> struct naturalPower <X, UINTMAX_C(1), false>;
  template <class X> struct naturalPower <X, UINTMAX_C(2), true>;
  template <class X> struct naturalPower <X, UINTMAX_C(3), false>;
  template <class X, std :: uintmax_t Y> struct naturalPower <X, Y, true>;
  template <class X, std :: uintmax_t Y> struct naturalPower <X, Y, false>;
  constexpr static valueType xNum = (y :: sign == '+') ? NumeratorX : DenominatorX;
  constexpr static valueType xDen = (y :: sign == '+') ? DenominatorX : NumeratorX;
  using initX = valueRatio<Type, SignX, xNum, xDen>;
  template <std :: uintmax_t Y>
	  using powerOfX = typename naturalPower <initX, Y, (Y % UINTMAX_C(2)) == UINTMAX_C(0)> :: type;
  public:
  using type = powerOfX<static_cast<std :: uintmax_t>(y :: num)>;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <class ... Empty>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 integralExponent<false, Empty...>
 {
  private:
  template <bool isPowerOfZero, class ... Empty2> struct Implementation;
  template <class ... Empty2> struct Implementation<true, Empty2...>;
  template <class ... Empty2> struct Implementation<false, Empty2...>;
  constexpr const static bool isPowerOfZero = //FIXME: Add check if is zero.
	  equalToValue <decltype(NumeratorX), NumeratorX, zero <decltype(NumeratorX)> :: value> :: value;
  public:
  using type = typename Implementation <isPowerOfZero> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <class ... Empty>
	 template <class X>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 integralExponent<true, Empty...> :: template
	 naturalPower<X, UINTMAX_C(0), true>
 {
  using type = typename identity <X> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <class ... Empty>
	 template <class X>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 integralExponent<true, Empty...> :: template
	 naturalPower<X, UINTMAX_C(1), false>
 {
  using type = X;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <class ... Empty>
	 template <class X>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 integralExponent<true, Empty...> :: template
	 naturalPower<X, UINTMAX_C(2), true>
 {
  using type = typename multipliesType <X, X> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <class ... Empty>
	 template <class X>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 integralExponent<true, Empty...> :: template
	 naturalPower<X, UINTMAX_C(3), false>
 {
  using type = typename multipliesType <X, X, X> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <class ... Empty>
	 template <class X, std :: uintmax_t Y>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 integralExponent<true, Empty...> :: template
	 naturalPower<X, Y, true>
 {
  private:
  constexpr const static std :: uintmax_t nextY = Y / UINTMAX_C(2);
  constexpr const static bool nextEven = ((nextY % UINTMAX_C(2)) == UINTMAX_C(0));
  using ans = typename naturalPower <X, nextY, nextEven> :: type;
  public:
  using type = typename multipliesType <ans, ans> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <class ... Empty>
	 template <class X, std :: uintmax_t Y>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 integralExponent<true, Empty...> :: template
	 naturalPower<X, Y, false>
 {
  private:
  constexpr const static std :: uintmax_t nextY = (Y - UINTMAX_C(1)) / UINTMAX_C(2);
  constexpr const static bool nextEven = ((nextY % UINTMAX_C(2)) == UINTMAX_C(0));
  using ans = typename naturalPower <X, nextY, nextEven> :: type;
  public:
  using type = typename multipliesType <X, ans, ans> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <class ... Empty>
	 template <class ... Empty2>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 integralExponent <false, Empty...> :: template
	 Implementation<true, Empty2...>
 {
  private:
  using x = valueRatio<Type, SignX, NumeratorX, DenominatorX>;
  public:
  using type = typename zero <x> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, char SignY, Type NumeratorY, Type DenominatorY>
	 template <class ... Empty>
	 template <class ... Empty2>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, valueRatio<Type, SignY, NumeratorY, DenominatorY> > :: template
	 integralExponent <false, Empty...> :: template
	 Implementation<false, Empty2...>
 {
  private:
  using x = valueRatio<Type, SignX, NumeratorX, DenominatorX>;
  using y = valueRatio<Type, SignY, NumeratorY, DenominatorY>;
  using exponent = typename multipliesType <y, typename logType <x> :: type> :: type;
  public:
  using type = typename expType <exponent> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> >
 {
  private:
  template <bool isUnsigned, class ... Empty> struct Implementation;
  template <class ... Empty> struct Implementation<true, Empty...>;
  template <class ... Empty> struct Implementation<false, Empty...>;
  public:
  using type = typename Implementation <std :: is_unsigned <TypeY> :: value> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<true, Empty...>
 {
  template <class X, TypeY Exp, bool is0, bool is1, bool is2, bool is3, bool isEven> struct power;
  template <class X, TypeY Exp> struct power<X, Exp, true, false, false, false, true>;
  template <class X, TypeY Exp> struct power<X, Exp, false, true, false, false, false>;
  template <class X, TypeY Exp> struct power<X, Exp, false, false, true, false, true>;
  template <class X, TypeY Exp> struct power<X, Exp, false, false, false, true, false>;
  template <class X, TypeY Exp> struct power<X, Exp, false, false, false, false, true>;
  template <class X, TypeY Exp> struct power<X, Exp, false, false, false, false, false>;
  constexpr const static TypeY const0 = zero <TypeY> :: value;
  constexpr const static TypeY const1 = identity <TypeY> :: value;
  constexpr const static TypeY const2 = plusValue <TypeY, const1, const1> :: value;
  constexpr const static TypeY const3 = plusValue <TypeY, const1, const1, const1> :: value;
  constexpr const static bool initialIs0 = equalToValue <TypeY, Y, const0> :: value;
  constexpr const static bool initialIs1 = equalToValue <TypeY, Y, const1> :: value;
  constexpr const static bool initialIs2 = equalToValue <TypeY, Y, const2> :: value;
  constexpr const static bool initialIs3 = equalToValue <TypeY, Y, const3> :: value;
  constexpr const static bool initialIsEven = equalToValue <TypeY, (Y % const2), const0> :: value;
  using x = valueRatio<Type, SignX, NumeratorX, DenominatorX>;
  public:
  using type = typename power <x, Y, initialIs0, initialIs1, initialIs2, initialIs3, initialIsEven> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<false, Empty...>
 {
  private:
  template <class X, TypeY Exp, bool is0, bool is1, bool is2, bool is3, bool isEven> struct power;
  template <class X, TypeY Exp> struct power<X, Exp, true, false, false, false, true>;
  template <class X, TypeY Exp> struct power<X, Exp, false, true, false, false, false>;
  template <class X, TypeY Exp> struct power<X, Exp, false, false, true, false, true>;
  template <class X, TypeY Exp> struct power<X, Exp, false, false, false, true, false>;
  template <class X, TypeY Exp> struct power<X, Exp, false, false, false, false, true>;
  template <class X, TypeY Exp> struct power<X, Exp, false, false, false, false, false>;
  constexpr const static TypeY const0 = zero <TypeY> :: value;
  constexpr const static TypeY const1 = identity <TypeY> :: value;
  constexpr const static TypeY const2 = plusValue <TypeY, const1, const1> :: value;
  constexpr const static TypeY const3 = plusValue <TypeY, const1, const1, const1> :: value;
  constexpr const static TypeY constM1 = negateValue <TypeY, const1> :: value;
  constexpr const static TypeY constM2 = negateValue <TypeY, const2> :: value;
  constexpr const static TypeY constM3 = negateValue <TypeY, const3> :: value;
  constexpr const static bool initialIs0 = equalToValue <TypeY, Y, const0> :: value;
  constexpr const static bool initialIs1 =
	  (equalToValue <TypeY, Y, const1> :: value) || (equalToValue <TypeY, Y, constM1> :: value);
  constexpr const static bool initialIs2 =
	  (equalToValue <TypeY, Y, const2> :: value) || (equalToValue <TypeY, Y, constM2> :: value);
  constexpr const static bool initialIs3 =
	  (equalToValue <TypeY, Y, const3> :: value) || (equalToValue <TypeY, Y, constM3> :: value);
  constexpr const static bool initialIsEven = equalToValue <TypeY, ((Y / const2) * const2), Y> :: value;
  constexpr const static bool positivePower = lessValue <TypeY, const0, Y> :: value;
  constexpr const static bool isBaseZero = //FIXME: Add check if is zero.
	  equalToValue <decltype(NumeratorX), NumeratorX, zero <decltype(NumeratorX)> :: value> :: value;
  static_assert(positivePower || !isBaseZero, "Value out of range.");
  using valueType = typename std :: add_const <Type> :: type;
  constexpr static valueType xNum = positivePower ? NumeratorX : DenominatorX;
  constexpr static valueType xDen = positivePower ? DenominatorX : NumeratorX;
  using x = valueRatio<Type, SignX, xNum, xDen>;
  public:
  using type = typename power <x, Y, initialIs0, initialIs1, initialIs2, initialIs3, initialIsEven> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
	 template <class X, TypeY Exp>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<true, Empty...> :: template
	 power<X, Exp, true, false, false, false, true>
 {
  using type = typename identity <X> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
	 template <class X, TypeY Exp>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<true, Empty...> :: template
	 power<X, Exp, false, true, false, false, false>
 {
  using type = X;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
	 template <class X, TypeY Exp>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<true, Empty...> :: template
	 power<X, Exp, false, false, true, false, true>
 {
  using type = typename multipliesType <X, X> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
	 template <class X, TypeY Exp>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<true, Empty...> :: template
	 power<X, Exp, false, false, false, true, false>
 {
  using type = typename multipliesType <X, X, X> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
	 template <class X, TypeY Exp>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<true, Empty...> :: template
	 power<X, Exp, false, false, false, false, true>
 {
  private:
  constexpr const static TypeY const0 = zero <TypeY> :: value;
  constexpr const static TypeY const1 = identity <TypeY> :: value;
  constexpr const static TypeY const2 = plusValue <TypeY, const1, const1> :: value;
  constexpr const static TypeY const3 = plusValue <TypeY, const1, const1, const1> :: value;
  constexpr const static TypeY newExp = Exp / const2;
  constexpr const static bool is0 = equalToValue <TypeY, newExp, const0> :: value;
  constexpr const static bool is1 = equalToValue <TypeY, newExp, const1> :: value;
  constexpr const static bool is2 = equalToValue <TypeY, newExp, const2> :: value;
  constexpr const static bool is3 = equalToValue <TypeY, newExp, const3> :: value;
  constexpr const static bool isEven = equalToValue <TypeY, newExp % const2, const0> :: value;
  using newX = typename power <X, newExp, is0, is1, is2, is3, isEven> :: type;
  public:
  using type = typename multipliesType <newX, newX> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
	 template <class X, TypeY Exp>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<true, Empty...> :: template
	 power<X, Exp, false, false, false, false, false>
 {
  private:
  constexpr const static TypeY const0 = zero <TypeY> :: value;
  constexpr const static TypeY const1 = identity <TypeY> :: value;
  constexpr const static TypeY const2 = plusValue <TypeY, const1, const1> :: value;
  constexpr const static TypeY const3 = plusValue <TypeY, const1, const1, const1> :: value;
  constexpr const static TypeY newExp = (Exp - const1) / const2;
  constexpr const static bool is0 = equalToValue <TypeY, newExp, const0> :: value;
  constexpr const static bool is1 = equalToValue <TypeY, newExp, const1> :: value;
  constexpr const static bool is2 = equalToValue <TypeY, newExp, const2> :: value;
  constexpr const static bool is3 = equalToValue <TypeY, newExp, const3> :: value;
  constexpr const static bool isEven = equalToValue <TypeY, newExp % const2, const0> :: value;
  using newX = typename power <X, newExp, is0, is1, is2, is3, isEven> :: type;
  public:
  using type = typename multipliesType <newX, newX, X> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
	 template <class X, TypeY Exp>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<false, Empty...> :: template
	 power<X, Exp, true, false, false, false, true>
 {
  using type = typename identity <X> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
	 template <class X, TypeY Exp>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<false, Empty...> :: template
	 power<X, Exp, false, true, false, false, false>
 {
  using type = X;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
	 template <class X, TypeY Exp>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<false, Empty...> :: template
	 power<X, Exp, false, false, true, false, true>
 {
  using type = typename multipliesType <X, X> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
	 template <class X, TypeY Exp>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<false, Empty...> :: template
	 power<X, Exp, false, false, false, true, false>
 {
  using type = typename multipliesType <X, X, X> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
	 template <class X, TypeY Exp>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<false, Empty...> :: template
	 power<X, Exp, false, false, false, false, true>
 {
  private:
  constexpr const static TypeY const0 = zero <TypeY> :: value;
  constexpr const static TypeY const1 = identity <TypeY> :: value;
  constexpr const static TypeY const2 = plusValue <TypeY, const1, const1> :: value;
  constexpr const static TypeY const3 = plusValue <TypeY, const1, const1, const1> :: value;
  constexpr const static TypeY constM1 = negateValue <TypeY, const1> :: value;
  constexpr const static TypeY constM2 = negateValue <TypeY, const2> :: value;
  constexpr const static TypeY constM3 = negateValue <TypeY, const3> :: value;
  constexpr const static TypeY newExp = Exp / const2;
  constexpr const static bool is0 = equalToValue <TypeY, newExp, const0> :: value;
  constexpr const static bool is1 =
	  (equalToValue <TypeY, newExp, const1> :: value) || (equalToValue <TypeY, newExp, constM1> :: value);
  constexpr const static bool is2 =
	  (equalToValue <TypeY, newExp, const2> :: value) || (equalToValue <TypeY, newExp, constM2> :: value);
  constexpr const static bool is3 =
	  (equalToValue <TypeY, newExp, const3> :: value) || (equalToValue <TypeY, newExp, constM3> :: value);
  constexpr const static bool isEven = equalToValue <TypeY, ((newExp / const2) * const2), newExp> :: value;
  using newX = typename power <X, newExp, is0, is1, is2, is3, isEven> :: type;
  public:
  using type = typename multipliesType <newX, newX> :: type;
 };

 template <class Type, char SignX, Type NumeratorX, Type DenominatorX, class TypeY, TypeY Y>
	 template <class ... Empty>
	 template <class X, TypeY Exp>
 struct powType<valueRatio<Type, SignX, NumeratorX, DenominatorX>, std :: integral_constant<TypeY, Y> > :: template
	 Implementation<false, Empty...> :: template
	 power<X, Exp, false, false, false, false, false>
 {
  private:
  constexpr const static TypeY const0 = zero <TypeY> :: value;
  constexpr const static TypeY const1 = identity <TypeY> :: value;
  constexpr const static TypeY const2 = plusValue <TypeY, const1, const1> :: value;
  constexpr const static TypeY const3 = plusValue <TypeY, const1, const1, const1> :: value;
  constexpr const static TypeY constM1 = negateValue <TypeY, const1> :: value;
  constexpr const static TypeY constM2 = negateValue <TypeY, const2> :: value;
  constexpr const static TypeY constM3 = negateValue <TypeY, const3> :: value;
  constexpr const static bool positivePower = lessValue <TypeY, const0, Exp> :: value;
  constexpr const static TypeY newExp = (Exp - (positivePower ? const1 : constM1)) / const2;
  constexpr const static bool is0 = equalToValue <TypeY, newExp, const0> :: value;
  constexpr const static bool is1 =
	  (equalToValue <TypeY, newExp, const1> :: value) || (equalToValue <TypeY, newExp, constM1> :: value);
  constexpr const static bool is2 =
	  (equalToValue <TypeY, newExp, const2> :: value) || (equalToValue <TypeY, newExp, constM2> :: value);
  constexpr const static bool is3 =
	  (equalToValue <TypeY, newExp, const3> :: value) || (equalToValue <TypeY, newExp, constM3> :: value);
  constexpr const static bool isEven = equalToValue <TypeY, ((newExp / const2) * const2), newExp> :: value;
  using newX = typename power <X, newExp, is0, is1, is2, is3, isEven> :: type;
  public:
  using type = typename multipliesType <newX, newX, X> :: type;
 };

 template <class TypeX, class TypeY, char SignX, TypeX NumeratorX, TypeX DenominatorX, char SignY, TypeY NumeratorY, TypeY DenominatorY>
	 struct powType<valueRatio<TypeX, SignX, NumeratorX, DenominatorX>, valueRatio<TypeY, SignY, NumeratorY, DenominatorY> >
	 : powType<
	 valueRatio<typename std :: common_type <TypeX, TypeY> :: type, SignX, static_cast<typename std :: common_type <TypeX, TypeY> :: type>(NumeratorX), static_cast<typename std :: common_type <TypeX, TypeY> :: type>(DenominatorX)>,
	 valueRatio<typename std :: common_type <TypeX, TypeY> :: type, SignY, static_cast<typename std :: common_type <TypeX, TypeY> :: type>(NumeratorY), static_cast<typename std :: common_type <TypeX, TypeY> :: type>(DenominatorY)> >
	 {};

 template <class TypeX, class TypeY, char SignX, TypeX NumeratorX, TypeX DenominatorX, char SignY, TypeY NumeratorY, TypeY DenominatorY>
	 constexpr typename powType <valueRatio<TypeX, SignX, NumeratorX, DenominatorX>, valueRatio<TypeY, SignY, NumeratorY, DenominatorY> > :: type
	 pow(valueRatio<TypeX, SignX, NumeratorX, DenominatorX>, valueRatio<TypeY, SignY, NumeratorY, DenominatorY>) noexcept;
}

template <class TypeX, class TypeY, char SignX, TypeX NumeratorX, TypeX DenominatorX, char SignY, TypeY NumeratorY, TypeY DenominatorY>
inline constexpr typename crap :: powType <crap :: valueRatio<TypeX, SignX, NumeratorX, DenominatorX>, crap :: valueRatio<TypeY, SignY, NumeratorY, DenominatorY> > :: type
crap :: pow(crap :: valueRatio<TypeX, SignX, NumeratorX, DenominatorX>, crap :: valueRatio<TypeY, SignY, NumeratorY, DenominatorY>) noexcept
{
 return {};
}
#endif

