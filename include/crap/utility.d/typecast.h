#ifndef CRAP_UTILITY_TYPECAST
#define CRAP_UTILITY_TYPECAST

#include <limits>
#include <ratio>
#include <type_traits>

#include "reproducevalue.h"
#include "../crap.d/secureabsvalue.h"
#include "../functional.d/arithmeticoperatorsfortype.h"
#include "../numbers.d/identity.h"
#include "../numbers.d/zero.h"
#include "../ratio.d/contracttype.h"
#include "../ratio.d/plustype.h"
#include "../ratio.d/valueratio.h"
#include "../version.d/nontypetemplateargs.h"

namespace crap
{
 template <class> struct typeCast;

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct typeCast<std :: ratio<Numerator, Denominator> >
 {
  private:
  template <class, class...> struct ontoImplementation;
  template <std :: intmax_t Num, std :: intmax_t Den>
	  struct ontoImplementation<std :: ratio<Num, Den> >;
  template <class Type, char Sign, Type Num, Type Den>
	  struct ontoImplementation<valueRatio<Type, Sign, Num, Den> >;
  template <char Sign, std :: uintmax_t Num, std :: uintmax_t Den>
	  struct ontoImplementation<valueRatio<std :: uintmax_t, Sign, Num, Den> >;
  template <class ... Empty> struct ontoImplementation<float, Empty...>;
  template <class ... Empty> struct ontoImplementation<double, Empty...>;
  template <class ... Empty> struct ontoImplementation<long double, Empty...>;
  public:
  template <class Type> using onto = ontoImplementation<Type>;
  template <class Type> using onto_t = typename onto <Type> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct typeCast<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  template <class> struct NeedScale;
  template <class OtherType, char Sign2, OtherType Num, OtherType Den>
	  struct NeedScale<valueRatio<OtherType, Sign2, Num, Den>>;

  template <bool, class> struct Implementation;
  template <bool Any, std :: intmax_t Num, std :: intmax_t Den>
	  struct Implementation<Any, std :: ratio<Num, Den> >;
  template <class OtherType, char OtherSign, OtherType OtherNumerator, OtherType OtherDenominator>
	  struct Implementation<true, valueRatio<OtherType, OtherSign, OtherNumerator, OtherDenominator> >;
  template <class OtherType, char OtherSign, OtherType OtherNumerator, OtherType OtherDenominator>
	  struct Implementation<false, valueRatio<OtherType, OtherSign, OtherNumerator, OtherDenominator> >;
  template <bool Any> struct Implementation<Any, float>;
  template <bool Any> struct Implementation<Any, double>;
  template <bool Any> struct Implementation<Any, long double>;
  public:
  template <class OtherType> using onto = Implementation<NeedScale <OtherType> :: value, OtherType>;
  template <class OtherType> using onto_t = typename onto <OtherType> :: type;
 };

 template <class Type, Type Value>
	 struct typeCast<std :: integral_constant<Type, Value> >
 {
  private:
#if (crap_nontype_template_args >= 201911L)  || (defined(__clang_major__) && (__clang_major__ >= 18) && (__cplusplus >= 201911L))
  template <bool IsUnsigned, bool IsFloatingPoint, class...>
	  struct Implementation;
  template <class ... Empty>
	  struct Implementation<false, false, Empty...>;
  template <class ... Empty>
	  struct Implementation<true, false, Empty...>;
  template <bool Any, class ... Empty>
	  struct Implementation<Any, true, Empty...>;
#else
  template <bool IsUnsigned, class...>
	  struct Implementation;
  template <class ... Empty>
	  struct Implementation<false, Empty...>;
  template <class ... Empty>
	  struct Implementation<true, Empty...>;
#endif
  public:
#if (crap_nontype_template_args >= 201911L)  || (defined(__clang_major__) && (__clang_major__ >= 18) && (__cplusplus >= 201911L))
  template <class OtherType>
	  using onto = typename
	  Implementation <std :: is_unsigned <Type> :: value, std :: is_floating_point <Type> :: value> :: template
	  onto <OtherType> :: type;
#else
  template <class OtherType>
	  using onto = typename
	  Implementation <std :: is_unsigned <Type> :: value> :: template
	  onto <OtherType> :: type;
#endif
  template <class OtherType> using onto_t = typename onto <OtherType> :: type;
 };
}

#include "../crap.d/picklargertype.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 template <std :: intmax_t Num, std :: intmax_t Den>
 struct typeCast<std :: ratio<Numerator, Denominator> > ::
	 ontoImplementation<std :: ratio<Num, Den> >
 {
  using type = typename contractType <std :: ratio<Numerator, Denominator> > :: type;
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 template <class Type, char Sign, Type Num, Type Den>
 struct typeCast<std :: ratio<Numerator, Denominator> > ::
	 ontoImplementation<valueRatio<Type, Sign, Num, Den> >
 {
  private:
  using orig = typename contractType <std :: ratio<Numerator, Denominator> > :: type;
  using valueType = typename std :: add_const<Type> :: type;
  constexpr static valueType const0 = zero <valueType> :: value;
  constexpr static valueType const1 = identity <valueType> :: value;
  using descr1 = valueRatio<std :: uintmax_t, '+', UINTMAX_C(0), UINTMAX_C(1)>;
  using descr2 = valueRatio<Type, '+', const0, const1>;
  using ans = typename typeCast <orig> :: template onto <descr1> :: type;
  public:
  using type = typename typeCast <ans> :: template onto <descr2> :: type;
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 template <char Sign, std :: uintmax_t Num, std :: uintmax_t Den>
 struct typeCast<std :: ratio<Numerator, Denominator> > ::
	 ontoImplementation<valueRatio<std :: uintmax_t, Sign, Num, Den> >
 {
  private:
  constexpr static const bool numNegative = (Numerator < zero <std :: intmax_t> :: value);
  constexpr static const bool denNegative = (Denominator < zero <std :: intmax_t> :: value);
  constexpr static const char sign = (numNegative == denNegative) ? '+' : '-';
  constexpr static const std :: uintmax_t num =
	  secureAbsValue <std :: intmax_t, Numerator> :: value;
  constexpr static const std :: uintmax_t den =
	  secureAbsValue <std :: intmax_t, Denominator> :: value;
  public:
  using type = valueRatio<std :: uintmax_t, sign, num, den>;
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 template <class ... Empty>
 struct typeCast<std :: ratio<Numerator, Denominator> > ::
	 ontoImplementation<float, Empty...>
 {
  constexpr const static float value =
	  static_cast<float>(static_cast<long double>(Numerator) / static_cast<long double>(Denominator));
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 template <class ... Empty>
 struct typeCast<std :: ratio<Numerator, Denominator> > ::
	 ontoImplementation<double, Empty...>
 {
  constexpr const static double value =
	  static_cast<double>(static_cast<long double>(Numerator) / static_cast<long double>(Denominator));
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 template <class ... Empty>
 struct typeCast<std :: ratio<Numerator, Denominator> > ::
	 ontoImplementation<long double, Empty...>
 {
  constexpr const static long double value =
	  static_cast<long double>(Numerator) / static_cast<long double>(Denominator);
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class>
 struct typeCast<valueRatio<Type, Sign, Numerator, Denominator> > :: NeedScale
 {
  constexpr static const bool value = false;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class OtherType, char OtherSign, OtherType OtherNumerator, OtherType OtherDenominator>
 struct typeCast<valueRatio<Type, Sign, Numerator, Denominator> > ::
	 NeedScale<valueRatio<OtherType, OtherSign, OtherNumerator, OtherDenominator>>
 {
  private:
  using largerType = typename pickLargerType <Type, OtherType> :: type;
  constexpr static const largerType lhsMax =
	  static_cast<largerType>(std :: numeric_limits <Type> :: max());
  constexpr static const largerType rhsMax =
	  static_cast<largerType>(std :: numeric_limits <OtherType> :: max());
  public:
  constexpr static const bool value = lhsMax > rhsMax;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <bool Any, std :: intmax_t Num, std :: intmax_t Den>
 struct typeCast<valueRatio<Type, Sign, Numerator, Denominator> > ::
	 Implementation<Any, std :: ratio<Num, Den> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const<std :: intmax_t> :: type;
  using orig = typename contractType <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  constexpr static const std :: intmax_t max = std :: numeric_limits <std :: intmax_t> :: max();
  constexpr static const std :: intmax_t min = std :: numeric_limits <std :: intmax_t> :: min();
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  using commonType = typename pickLargerType <std :: uintmax_t, Type> :: type;
  constexpr static const bool numOverflow1 =
	  (static_cast<commonType>(orig :: num) > static_cast<commonType>(max));
  constexpr static const bool denOverflow1 =
	  (static_cast<commonType>(orig :: den) > static_cast<commonType>(max));
  constexpr static const bool needScale1 = numOverflow1 || denOverflow1;
  constexpr static scaleType numOverflow1Scale =
	  numOverflow1 ? (static_cast<scaleType>(max) / static_cast<scaleType>(orig :: num)) : infinity;
  constexpr static scaleType denOverflow1Scale =
	  denOverflow1 ? (static_cast<scaleType>(max) / static_cast<scaleType>(orig :: den)) : infinity;
  constexpr static scaleType scale1 =
	  (numOverflow1Scale < denOverflow1Scale) ? numOverflow1Scale : denOverflow1Scale;
  constexpr static scaleType scaledNum1 =
	  needScale1 ? (scale1 * static_cast<scaleType>(orig :: num)) : static_cast<scaleType>(orig :: num);
  constexpr static scaleType scaledDen1 =
	  needScale1 ? (scale1 * static_cast<scaleType>(orig :: den)) : static_cast<scaleType>(orig :: den);
  constexpr static valueType scaledNum1InRange =
	  (scaledNum1 < 0.0l) ?
	  zero <valueType> :: value :
	  ((scaledNum1 > static_cast<valueType>(max)) ? max : static_cast<valueType>(scaledNum1));
  constexpr static valueType scaledDen1InRange =
	  (scaledDen1 < 1.0l) ?
	  identity <valueType> :: value :
	  ((scaledDen1 > static_cast<valueType>(max)) ? max : static_cast<valueType>(scaledDen1));
  constexpr static valueType absNum = needScale1 ? scaledNum1InRange : static_cast<valueType>(orig :: num);
  constexpr static valueType absDen = needScale1 ? scaledDen1InRange : static_cast<valueType>(orig :: den);
  constexpr static const bool isNegative = (orig :: sign == '-');
  constexpr static const bool numUnderflow2 = isNegative ? (zero <valueType> :: value < (min + absNum)) : false;
  constexpr static const bool needScale2 = numUnderflow2;
  constexpr static scaleType numUnderflow2Scale =
	  numUnderflow2 ? (static_cast<scaleType>(min) / (-static_cast<scaleType>(absNum))) : infinity;
  constexpr static scaleType scale2 = numUnderflow2Scale;
  constexpr static scaleType scaledNum2 =
	  needScale2 ?
	  (scale2 * (isNegative ? -1.0l : 1.0l) * static_cast<scaleType>(absNum)) :
	  static_cast<scaleType>(isNegative ? -absNum : absNum);
  constexpr static scaleType scaledDen2 =
	  needScale2 ? (scale2 * static_cast<scaleType>(absDen)) : static_cast<scaleType>(absDen);
  constexpr static valueType scaledNum2InRange =
	  (scaledNum2 < static_cast<scaleType>(min)) ?
	  min :
	  ((scaledNum2 > static_cast<scaleType>(max)) ? max : static_cast<valueType>(scaledNum2));
  constexpr static valueType scaledDen2InRange =
	  (scaledDen2 < 1.0l) ?
	  identity <valueType> :: value :
	  ((scaledDen2 > static_cast<scaleType>(max)) ? max : static_cast<valueType>(scaledDen2));
  constexpr static valueType num = needScale2 ? scaledNum2InRange : (isNegative ? -absNum : absNum);
  constexpr static valueType den = needScale2 ? scaledDen2InRange : absDen;
  public:
  using type = typename contractType <std :: ratio<num, den> > :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class OtherType, char OtherSign, OtherType OtherNumerator, OtherType OtherDenominator>
 struct typeCast <valueRatio<Type, Sign, Numerator, Denominator> > ::
	 Implementation<true, valueRatio<OtherType, OtherSign, OtherNumerator, OtherDenominator> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const<OtherType> :: type;
  using orig = typename contractType <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  constexpr static const std :: intmax_t max = std :: numeric_limits <valueType> :: max();
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  using commonType = typename pickLargerType <std :: uintmax_t, Type> :: type;
  constexpr static const bool numOverflow =
	  (static_cast<commonType>(orig :: num) > static_cast<commonType>(max));
  constexpr static const bool denOverflow =
	  (static_cast<commonType>(orig :: den) > static_cast<commonType>(max));
  constexpr static const bool needScale = numOverflow || denOverflow;
  constexpr static scaleType numOverflowScale =
	  numOverflow ? (static_cast<scaleType>(max) / static_cast<scaleType>(orig :: num)) : infinity;
  constexpr static scaleType denOverflowScale =
	  denOverflow ? (static_cast<scaleType>(max) / static_cast<scaleType>(orig :: den)) : infinity;
  constexpr static scaleType scale = (numOverflowScale < denOverflowScale) ? numOverflowScale : denOverflowScale;
  constexpr static scaleType scaledNum =
	  needScale ? (scale * static_cast<scaleType>(orig :: num)) : static_cast<scaleType>(orig :: num);
  constexpr static scaleType scaledDen =
	  needScale ? (scale * static_cast<scaleType>(orig :: den)) : static_cast<scaleType>(orig :: den);
  constexpr static valueType scaledNumInRange =
	  (scaledNum < 0.0l) ?
	  zero <valueType> :: value :
	  ((scaledNum > static_cast<scaleType>(max)) ? max : static_cast<valueType>(scaledNum));
  constexpr static valueType scaledDenInRange =
	  (scaledDen < 1.0l) ?
	  identity <valueType> :: value :
	  ((scaledDen > static_cast<scaleType>(max)) ? max : static_cast<valueType>(scaledDen));
  constexpr static valueType num = needScale ? scaledNumInRange : static_cast<valueType>(orig :: num);
  constexpr static valueType den = needScale ? scaledDenInRange : static_cast<valueType>(orig :: den);
  public:
  using type = typename contractType <valueRatio<OtherType, Sign, num, den> > :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class OtherType, char OtherSign, OtherType OtherNumerator, OtherType OtherDenominator>
 struct typeCast <valueRatio<Type, Sign, Numerator, Denominator> > ::
	 Implementation<false, valueRatio<OtherType, OtherSign, OtherNumerator, OtherDenominator> >
 {
  using type = typename contractType <valueRatio<OtherType, Sign, static_cast<OtherType>(Numerator), static_cast<OtherType>(Denominator)> > :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <bool Any>
 struct typeCast <valueRatio<Type, Sign, Numerator, Denominator> > ::
	 Implementation<Any, float>
 {
  constexpr const static float value = ((Sign == '-') ? -1.0f : 1.0) *
	  static_cast<float>(static_cast<long double>(Numerator) / static_cast<long double>(Denominator));
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <bool Any>
 struct typeCast <valueRatio<Type, Sign, Numerator, Denominator> > ::
	 Implementation<Any, double>
 {
  constexpr const static double value = ((Sign == '-') ? -1.0 : 1.0) *
	  static_cast<double>(static_cast<long double>(Numerator) / static_cast<long double>(Denominator));
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <bool Any>
 struct typeCast <valueRatio<Type, Sign, Numerator, Denominator> > ::
	 Implementation<Any, long double>
 {
  constexpr const static long double value = ((Sign == '-') ? -1.0l : 1.0l) *
	  (static_cast<long double>(Numerator) / static_cast<long double>(Denominator));
 };

#if (crap_nontype_template_args >= 201911L)  || (defined(__clang_major__) && (__clang_major__ >= 18) && (__cplusplus >= 201911L))
 template <class Type, Type Value>
	 template <class ... Empty>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation<false, false, Empty...>
 {
  template <class...> struct onto;
  template <class Type2, char Sign, Type2 Num, Type2 Den>
	  struct onto<valueRatio<Type2, Sign, Num, Den> >;
  template <std :: intmax_t Num, std :: intmax_t Den>
	  struct onto<std :: ratio<Num, Den> >;
 };

 template <class Type, Type Value>
	 template <class ... Empty>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation<true, false, Empty...>
 {
  template <class...> struct onto;
  template <class Type2, char Sign, Type2 Num, Type2 Den>
	  struct onto<valueRatio<Type2, Sign, Num, Den> >;
  template <std :: intmax_t Num, std :: intmax_t Den>
	  struct onto<std :: ratio<Num, Den> >;
 };

 template <class Type, Type Value>
	 template <bool Any, class ... Empty>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation<Any, true, Empty...>
 {
  template <class...> struct onto;
  template <class Type2, char Sign, Type2 Num, Type2 Den>
	  struct onto<valueRatio<Type2, Sign, Num, Den> >;
  template <std :: intmax_t Num, std :: intmax_t Den>
	  struct onto<std :: ratio<Num, Den> >;
 };

 template <class Type, Type Value>
	 template <class ... Empty>
	 template <class Type2, char Sign, Type2 Num, Type2 Den>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation <false, false, Empty...> ::
	 onto<valueRatio<Type2, Sign, Num, Den> >
 {
  private:
  using passed = valueRatio<Type2, Sign, Num, Den>;
  using valueType = typename std :: make_unsigned <Type> :: type;
  constexpr const static char sign =
	  ((Value < zero <Type> :: value) ? '-' : '+');
  constexpr const static valueType num =
	  secureAbsValue <Type, Value> :: value;
  constexpr const static valueType den =
	  identity <valueType> :: value;
  using result = valueRatio<valueType, sign, num, den>;
  public:
  using type = typename
	  typeCast <result> :: template
	  onto <passed> :: type;
 };

 template <class Type, Type Value>
	 template <class ... Empty>
	 template <std :: intmax_t Num, std :: intmax_t Den>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation <false, false, Empty...> ::
	 onto<std :: ratio<Num, Den> >
 {
  //TODO: Add over/underflow check.
  using type = std :: ratio<Value, identity <std :: intmax_t> :: value>;
 };

 template <class Type, Type Value>
	 template <class ... Empty>
	 template <class Type2, char Sign, Type2 Num, Type2 Den>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation <true, false, Empty...> ::
	 onto<valueRatio<Type2, Sign, Num, Den> >
 {
  private:
  using passed = valueRatio<Type2, Sign, Num, Den>;
  using result =
	  valueRatio<Type, '+', Value, identity <Type> :: value>;
  public:
  using type = typename
	  typeCast <result> :: template
	  onto <passed> :: type;
 };

 template <class Type, Type Value>
	 template <class ... Empty>
	 template <std :: intmax_t Num, std :: intmax_t Den>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation <true, false, Empty...> ::
	 onto<std :: ratio<Num, Den> >
 {
  private:
  using result =
	  valueRatio<Type, '+', Value, identity <Type> :: value>;
  public:
  using type = typename
	  typeCast <result> :: template
	  onto <std :: ratio<Num, Den> > :: type;
 };

 template <class Type, Type Value>
	 template <bool Any, class ... Empty>
	 template <class Type2, char Sign, Type2 Num, Type2 Den>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation <Any, true, Empty...> ::
	 onto<valueRatio<Type2, Sign, Num, Den> >
 {
  private:
  static_assert(!(Value != Value), "NaN not supported yet");
  constexpr const static Type valMin = std :: numeric_limits <Type> :: min();
  constexpr const static Type valMax = std :: numeric_limits <Type> :: max();
  constexpr const static Type valZero = zero <Type> :: value;
  static_assert(valMin + valMax >= valZero, "Range assymetric in that way not supported yet.");
  constexpr const static Type absValue = ((Value < valZero) ? (-Value) : Value);
  constexpr const static Type2 max = std :: numeric_limits <Type2> :: max();
  static_assert(absValue <= static_cast<Type>(max), "Overflow/infinity not supported yet.");
  constexpr const static Type2 const1 = identity <Type2> :: value;
  using integerPart = valueRatio<Type2, '+', static_cast<Type2>(absValue), const1>;
  constexpr const static int digits = std :: numeric_limits <Type2> :: digits;
  static_assert(digits > 0, "Exotic digits not supported.");
  constexpr const static int radix = std :: numeric_limits <Type2> :: radix;
  static_assert(radix > 1, "Exotic radices not supported.");
  constexpr const static Type invRadix =
	  static_cast<Type>(const1) / static_cast<Type>(radix);
  constexpr const static Type trueMin =
	  reproduceValue <digits - 1, Type, invRadix> :: template
	  type <arithmeticOperatorsForType <Type> :: template Multiplies> :: value;
  constexpr const static Type fracPart =
	  absValue - static_cast<Type>(static_cast<Type2>(absValue));
  constexpr const static bool inRange = !(fracPart < trueMin);
  constexpr const static Type2 initDen = static_cast<Type2>(radix);
  template <class Partial, Type2 CurDen, Type SubValue, bool InRange, int Digit, int Max>
	  struct SubImplementation;
  template <class Partial, Type2 CurDen, Type SubValue, int Max>
	  struct SubImplementation<Partial, CurDen, SubValue, true, Max, Max>;
  template <class Partial, Type2 CurDen, Type SubValue, int Max>
	  struct SubImplementation<Partial, CurDen, SubValue, false, Max, Max>;
  template <class Partial, Type2 CurDen, Type SubValue, int Digit, int Max>
	  struct SubImplementation<Partial, CurDen, SubValue, true, Digit, Max>;
  template <class Partial, Type2 CurDen, Type SubValue, int Digit, int Max>
	  struct SubImplementation<Partial, CurDen, SubValue, false, Digit, Max>;
  constexpr const static char sign = ((Value < valZero) ? '-' : '+');
  using result = typename
	  SubImplementation<integerPart, initDen, fracPart, inRange, 2, digits> :: type;
  public:
  using type = valueRatio<Type2, sign, result :: num, result :: den>;
 };

 template <class Type, Type Value>
	 template <bool Any, class ... Empty>
	 template <std :: intmax_t Num, std :: intmax_t Den>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation <Any, true, Empty...> ::
	 onto<std :: ratio<Num, Den> >
 {
  private:
  using passed = std :: integral_constant<Type, Value>;
  using partResult = typename
	  typeCast <passed> :: template
	  onto <valueRatio<std :: uintmax_t, '+', UINTMAX_C(0), UINTMAX_C(1)> > ::
	  type;
  public:
  using type = typename
	  typeCast <partResult> :: template
	  onto <std :: ratio<Num, Den> > :: type;
 };

 template <class Type, Type Value>
	 template <bool Any, class ... Empty>
	 template <class Type2, char Sign, Type2 Num, Type2 Den>
	 template <class Partial, Type2 CurDen, Type SubValue, int Max>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation <Any, true, Empty...> ::
	 onto <valueRatio<Type2, Sign, Num, Den> > ::
	 SubImplementation<Partial, CurDen, SubValue, true, Max, Max>
 {
  private:
  constexpr const static int radix = std :: numeric_limits <Type2> :: radix;
  constexpr const static Type valZero = zero <Type> :: value;
  constexpr const static Type shiftedSub = SubValue * static_cast<Type>(radix);
  constexpr const static char sign = ((shiftedSub < valZero) ? '-' : '+');
  constexpr const static Type2 num =
	  static_cast<Type2>((shiftedSub < valZero) ? (-shiftedSub) : shiftedSub);
  using partialShift = valueRatio<Type2, sign, num, CurDen>;
  public:
  using type = typename plusType <Partial, partialShift> :: type;
 };

 template <class Type, Type Value>
	 template <bool Any, class ... Empty>
	 template <class Type2, char Sign, Type2 Num, Type2 Den>
	 template <class Partial, Type2 CurDen, Type SubValue, int Max>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation <Any, true, Empty...> ::
	 onto <valueRatio<Type2, Sign, Num, Den> > ::
	 SubImplementation<Partial, CurDen, SubValue, false, Max, Max>
 {
  using type = Partial;
 };

 template <class Type, Type Value>
	 template <bool Any, class ... Empty>
	 template <class Type2, char Sign, Type2 Num, Type2 Den>
	 template <class Partial, Type2 CurDen, Type SubValue, int Digit, int Max>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation <Any, true, Empty...> ::
	 onto <valueRatio<Type2, Sign, Num, Den> > ::
	 SubImplementation<Partial, CurDen, SubValue, true, Digit, Max>
 {
  private:
  constexpr const static int radix = std :: numeric_limits <Type2> :: radix;
  constexpr const static Type valZero = zero <Type> :: value;
  constexpr const static Type shiftedSub = SubValue * static_cast<Type>(radix);
  constexpr const static char sign = ((shiftedSub < valZero) ? '-' : '+');
  constexpr const static Type2 num =
	  static_cast<Type2>((shiftedSub < valZero) ? (-shiftedSub) : shiftedSub);
  using partialShift = valueRatio<Type2, sign, num, CurDen>;
  using newPartial = typename plusType <Partial, partialShift> :: type;
  constexpr const static Type newSub =
	  ((shiftedSub < valZero) ?
	  (shiftedSub + static_cast<Type>(num)) :
	  (shiftedSub - static_cast<Type>(num)));
  constexpr const static Type2 newDen = CurDen * static_cast<Type2>(radix);
  constexpr const static Type2 const1 = identity <Type2> :: value;
  constexpr const static Type invRadix =
	  static_cast<Type>(const1) / static_cast<Type>(radix);
  constexpr const static Type trueMin =
	  reproduceValue <Max - 1, Type, invRadix> :: template
	  type <arithmeticOperatorsForType <Type> :: template Multiplies> :: value;
  constexpr const static bool newInRange = !(newSub < trueMin);
  public:
  using type = typename
	  SubImplementation <newPartial, newDen, newSub, newInRange, Digit + 1, Max> :: type;
 };

 template <class Type, Type Value>
	 template <bool Any, class ... Empty>
	 template <class Type2, char Sign, Type2 Num, Type2 Den>
	 template <class Partial, Type2 CurDen, Type SubValue, int Digit, int Max>
 struct typeCast <std :: integral_constant<Type, Value> > ::
	 Implementation <Any, true, Empty...> ::
	 onto <valueRatio<Type2, Sign, Num, Den> > ::
	 SubImplementation<Partial, CurDen, SubValue, false, Digit, Max>
 {
  using type = Partial;
 };
#else
 template <class Type, Type Value>
	 template <class ... Empty>
 struct typeCast<std :: integral_constant<Type, Value> > ::
	 Implementation<false, Empty...>
 {
  template <class...> struct onto;
  template <class Type2, char Sign, Type2 Num, Type2 Den>
	  struct onto<valueRatio<Type2, Sign, Num, Den> >;
  template <std :: intmax_t Num, std :: intmax_t Den>
	  struct onto<std :: ratio<Num, Den> >;
 };

 template <class Type, Type Value>
	 template <class ... Empty>
 struct typeCast<std :: integral_constant<Type, Value> > ::
	 Implementation<true, Empty...>
 {
  template <class...> struct onto;
  template <class Type2, char Sign, Type2 Num, Type2 Den>
	  struct onto<valueRatio<Type2, Sign, Num, Den> >;
  template <std :: intmax_t Num, std :: intmax_t Den>
	  struct onto<std :: ratio<Num, Den> >;
 };

 template <class Type, Type Value>
	 template <class ... Empty>
	 template <class Type2, char Sign, Type2 Num, Type2 Den>
 struct typeCast<std :: integral_constant<Type, Value> > ::
	 Implementation <false, Empty...> ::
	 onto<valueRatio<Type2, Sign, Num, Den> >
 {
  private:
  using passed = valueRatio<Type2, Sign, Num, Den>;
  using valueType = typename std :: make_unsigned <Type> :: type;
  constexpr const static char sign =
	  ((Value < zero <Type> :: value) ? '-' : '+');
  constexpr const static valueType num =
	  secureAbsValue <Type, Value> :: value;
  constexpr const static valueType den =
	  identity <valueType> :: value;
  using result = valueRatio<valueType, sign, num, den>;
  public:
  using type = typename
	  typeCast <result> :: template
	  onto <passed> :: type;
 };

 template <class Type, Type Value>
	 template <class ... Empty>
	 template <std :: intmax_t Num, std :: intmax_t Den>
 struct typeCast<std :: integral_constant<Type, Value> > ::
	 Implementation <false, Empty...> ::
	 onto<std :: ratio<Num, Den> >
 {
  //TODO: Add over/underflow check.
  using type = std :: ratio<Value, identity <std :: intmax_t> :: value>;
 };

 template <class Type, Type Value>
	 template <class ... Empty>
	 template <class Type2, char Sign, Type2 Num, Type2 Den>
 struct typeCast<std :: integral_constant<Type, Value> > ::
	 Implementation <true, Empty...> ::
	 onto<valueRatio<Type2, Sign, Num, Den> >
 {
  private:
  using passed = valueRatio<Type2, Sign, Num, Den>;
  using result =
	  valueRatio<Type, '+', Value, identity <Type> :: value>;
  public:
  using type = typename
	  typeCast <result> :: template
	  onto <passed> :: type;
 };

 template <class Type, Type Value>
	 template <class ... Empty>
	 template <std :: intmax_t Num, std :: intmax_t Den>
 struct typeCast<std :: integral_constant<Type, Value> > ::
	 Implementation <true, Empty...> ::
	 onto<std :: ratio<Num, Den> >
 {
  private:
  using result =
	  valueRatio<Type, '+', Value, identity <Type> :: value>;
  public:
  using type = typename
	  typeCast <result> :: template
	  onto <std :: ratio<Num, Den> > :: type;
 };
#endif
}
#endif

