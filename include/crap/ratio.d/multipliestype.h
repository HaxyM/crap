#ifndef CRAP_RATIO_MULTIPLIESTYPE
#define CRAP_RATIO_MULTIPLIESTYPE

#include <cmath>
#include <limits>
#include <type_traits>

#include "contracttype.h"
#include "valueratio.h"
#include "../functional.d/multipliestype.h"
#include "../numbers.d/identity.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/reducetype.h"
#include "../utility.d/typeidentity.h"

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct multipliesType<valueRatio<Type, Sign, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, Sign, Numerator, Denominator> > {};

 template <class Type, char Sign1, Type Numerator1, Type Denominator1, char Sign2, Type Numerator2, Type Denominator2>
 struct multipliesType<valueRatio<Type, Sign1, Numerator1, Denominator1>, valueRatio<Type, Sign2, Numerator2, Denominator2> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const <Type> :: type;
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static valueType max = std :: numeric_limits <valueType> :: max();
  constexpr const static char sign = (Sign1 == Sign2) ? '+' : '-';
  using contracted1 = typename contractType <valueRatio<Type, Sign1, Numerator1, Denominator2> > :: type;
  using contracted2 = typename contractType <valueRatio<Type, Sign2, Numerator2, Denominator1> > :: type;
  constexpr const static bool numOverflow = (contracted2 :: num > zero <valueType> :: value) ? (contracted1 :: num > (max / contracted2 :: num)) : false;
  constexpr const static bool denOverflow = (contracted1 :: den > (max / contracted2 :: den));
  constexpr const static bool needScale = (numOverflow || denOverflow);
  constexpr static scaleType numOverflowScale = numOverflow ? (static_cast<scaleType>(max) / static_cast<scaleType>(contracted1 :: num) / static_cast<scaleType>(contracted2 :: num)) : infinity;
  constexpr static scaleType denOverflowScale = denOverflow ? (static_cast<scaleType>(max) / static_cast<scaleType>(contracted1 :: den) / static_cast<scaleType>(contracted2 :: den)) : infinity;
  constexpr static scaleType scale = (numOverflowScale < denOverflowScale) ? numOverflowScale : denOverflowScale;
  constexpr static scaleType scaledDenominator = needScale ? (scale * static_cast<scaleType>(contracted1 :: den) * static_cast<scaleType>(contracted2 :: den)) : static_cast<scaleType>(contracted1 :: den * contracted2 :: den);
  constexpr static scaleType scaledNumerator = needScale ? (scale * static_cast<scaleType>(contracted1 :: num) * static_cast<scaleType>(contracted2 :: num)) : static_cast<scaleType>(contracted1 :: num * contracted2 :: num);
  constexpr static valueType scaledNumeratorInRange = (scaledNumerator < 0.0l) ? zero <valueType> :: value : ((scaledNumerator > static_cast<scaleType>(max)) ? max : static_cast<valueType>(scaledNumerator));
  constexpr static valueType numerator = needScale ? scaledNumeratorInRange : (contracted1 :: num * contracted2 :: num);
  constexpr static valueType scaledDenominatorInRange = (scaledDenominator < 1.0l) ? identity <valueType> :: value : ((scaledDenominator > static_cast<scaleType>(max) ? max : static_cast<valueType>(scaledDenominator)));
  constexpr static valueType denominator = needScale ? scaledDenominatorInRange : (contracted1 :: den * contracted2 :: den);
  public:
  using type = typename contractType <valueRatio<Type, sign, numerator, denominator> > :: type; //TODO: Consider contracting optional on overflow.
 };

 template <class Type, char ... Signs, Type ... Numerators, Type ... Denominators>
	 struct multipliesType<valueRatio<Type, Signs, Numerators, Denominators>...>
	 : reduceType<multipliesType, valueRatio<Type, Signs, Numerators, Denominators>...> {};

 template <class Type1, class Type2, char Sign1, Type1 Numerator1, Type1 Denominator1, char Sign2, Type2 Numerator2, Type2 Denominator2>
	 struct multipliesType<valueRatio<Type1, Sign1, Numerator1, Denominator1>, valueRatio<Type2, Sign2, Numerator2, Denominator2> >
	 : multipliesType<
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, Sign1, static_cast<typename std :: common_type <Type1, Type2> :: type>(Numerator1), static_cast<typename std :: common_type <Type1, Type2> :: type>(Denominator1)>,
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, Sign2, static_cast<typename std :: common_type <Type1, Type2> :: type>(Numerator2), static_cast<typename std :: common_type <Type1, Type2> :: type>(Denominator2)> >
	 {};
}

template <class Type1, class Type2, char Sign1, Type1 Numerator1, Type1 Denominator1, char Sign2, Type2 Numerator2, Type2 Denominator2>
inline constexpr typename crap :: multipliesType <crap :: valueRatio<Type1, Sign1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Sign2, Numerator2, Denominator2> > :: type
operator * (crap :: valueRatio<Type1, Sign1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Sign2, Numerator2, Denominator2> ) noexcept
{
 return {};
}
#endif
