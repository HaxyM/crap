#ifndef CRAP_UTILITY_TYPECAST
#define CRAP_UTILITY_TYPECAST

#include <limits>
#include <ratio>
#include <type_traits>

#include "../ratio.d/contracttype.h"
#include "../ratio.d/valueratio.h"

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
	  struct NeedScale<valueRatio<OtherType, Sign2, Num, Den> >;

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

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 template <std :: intmax_t Num, std :: intmax_t Den>
 struct typeCast<std :: ratio<Numerator, Denominator> > :: template
	 ontoImplementation<std :: ratio<Num, Den> >
 {
  using type = typename contractType <std :: ratio<Numerator, Denominator> > :: type;
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 template <class Type, char Sign, Type Num, Type Den>
 struct typeCast<std :: ratio<Numerator, Denominator> > :: template
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
 struct typeCast<std :: ratio<Numerator, Denominator> > :: template
	 ontoImplementation<valueRatio<std :: uintmax_t, Sign, Num, Den> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  using orig = typename contractType <std :: ratio<Numerator, Denominator> > :: type;
  constexpr static const std :: intmax_t max = std :: numeric_limits <std :: intmax_t> :: max();
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static const bool numNegative = (orig :: num < zero <std :: intmax_t> :: value);
  constexpr static const bool denNegative = (orig :: den < zero <std :: intmax_t> :: value);
  constexpr static scaleType numSignChanger = numNegative ? -1.0l : 1.0l;
  constexpr static scaleType denSignChanger = denNegative ? -1.0l : 1.0l;
  constexpr static const char sign = (numNegative == denNegative) ? '+' : '-';
  constexpr static const bool numOverflow =
	  numNegative ? (zero <std :: intmax_t> :: value > max + orig :: num) : false;
  constexpr static const bool denOverflow =
	  denNegative ? (zero <std :: intmax_t> :: value > max + orig :: den) : false;
  constexpr static const bool needScale = numOverflow || denOverflow;
  constexpr static scaleType numOverflowScale =
	  numOverflow ? (static_cast<scaleType>(max) / (-static_cast<scaleType>(orig :: num))) : infinity;
  constexpr static scaleType denOverflowScale =
	  denOverflow ? (static_cast<scaleType>(max) / (-static_cast<scaleType>(orig :: den))) : infinity;
  constexpr static scaleType scale = (numOverflowScale < denOverflowScale) ? numOverflowScale : denOverflowScale;
  constexpr static scaleType scaledNum =
	  needScale ?
	  (scale * numSignChanger * static_cast<scaleType>(orig :: num)) :
	  (numSignChanger * static_cast<scaleType>(orig :: num));
  constexpr static scaleType scaledDen =
	  needScale ?
	  (scale * denSignChanger * static_cast<scaleType>(orig :: den)) :
	  (denSignChanger * static_cast<scaleType>(orig :: den));
  constexpr static valueType scaledNumInRange =
	  (scaledNum < 0.0l) ? zero <std :: uintmax_t> :: value :
	  ((scaledNum > static_cast<scaleType>(max)) ? max : static_cast<valueType>(scaledNum));
  constexpr static valueType scaledDenInRange =
	  (scaledDen < 1.0l) ?
	  identity <std :: uintmax_t> :: value :
	  ((scaledDen > static_cast<scaleType>(max)) ? max : static_cast<valueType>(scaledDen));
  constexpr static valueType num =
	  needScale ?
	  scaledNumInRange :
	  static_cast<valueType>(numNegative ? -(orig :: num) : orig :: num);
  constexpr static valueType den =
	  needScale ?
	  scaledDenInRange :
	  static_cast<valueType>(denNegative ? -(orig :: den) : orig :: den);
  public:
  using type = valueRatio<std :: uintmax_t, sign, num, den>;
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 template <class ... Empty>
 struct typeCast<std :: ratio<Numerator, Denominator> > :: template
	 ontoImplementation<float, Empty...>
 {
  constexpr const static float value =
	  static_cast<float>(static_cast<long double>(Numerator) / static_cast<long double>(Denominator));
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 template <class ... Empty>
 struct typeCast<std :: ratio<Numerator, Denominator> > :: template
	 ontoImplementation<double, Empty...>
 {
  constexpr const static double value =
	  static_cast<double>(static_cast<long double>(Numerator) / static_cast<long double>(Denominator));
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 template <class ... Empty>
 struct typeCast<std :: ratio<Numerator, Denominator> > :: template
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
 struct typeCast<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 NeedScale<valueRatio<OtherType, OtherSign, OtherNumerator, OtherDenominator> >
 {
  private:
  constexpr static const std :: uintmax_t lhsMax =
	  static_cast<std :: uintmax_t>(std :: numeric_limits <Type> :: max());
  constexpr static const std :: uintmax_t rhsMax =
	  static_cast<std :: uintmax_t>(std :: numeric_limits <OtherType> :: max());
  public:
  constexpr static const bool value = lhsMax > rhsMax;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <bool Any, std :: intmax_t Num, std :: intmax_t Den>
 struct typeCast<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation<Any, std :: ratio<Num, Den> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const<std :: intmax_t> :: type;
  using orig = typename contractType <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  constexpr static const std :: intmax_t max = std :: numeric_limits <std :: intmax_t> :: max();
  constexpr static const std :: intmax_t min = std :: numeric_limits <std :: intmax_t> :: min();
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static const bool numOverflow1 =
	  (static_cast<std :: uintmax_t>(orig :: num) > static_cast<std :: uintmax_t>(max));
  constexpr static const bool denOverflow1 =
	  (static_cast<std :: uintmax_t>(orig :: den) > static_cast<std :: uintmax_t>(max));
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
 struct typeCast<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation<true, valueRatio<OtherType, OtherSign, OtherNumerator, OtherDenominator> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const<OtherType> :: type;
  using orig = typename contractType <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  constexpr static const std :: intmax_t max = std :: numeric_limits <valueType> :: max();
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static const bool numOverflow =
	  (static_cast<std :: uintmax_t>(orig :: num) > static_cast<std :: uintmax_t>(max));
  constexpr static const bool denOverflow =
	  (static_cast<std :: uintmax_t>(orig :: den) > static_cast<std :: uintmax_t>(max));
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
 struct typeCast<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation<false, valueRatio<OtherType, OtherSign, OtherNumerator, OtherDenominator> >
 {
  using type = typename contractType <valueRatio<OtherType, Sign, static_cast<OtherType>(Numerator), static_cast<OtherType>(Denominator)> > :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <bool Any>
 struct typeCast<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation<Any, float>
 {
  constexpr const static float value =
	  static_cast<float>(static_cast<long double>(Numerator) / static_cast<long double>(Denominator));
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <bool Any>
 struct typeCast<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation<Any, double>
 {
  constexpr const static double value =
	  static_cast<double>(static_cast<long double>(Numerator) / static_cast<long double>(Denominator));
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <bool Any>
 struct typeCast<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation<Any, long double>
 {
  constexpr const static long double value =
	  static_cast<long double>(Numerator) / static_cast<long double>(Denominator);
 };
}
#endif

