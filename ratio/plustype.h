#ifndef CRAP_RATIO_PLUSTYPE
#define CRAP_RATIO_PLUSTYPE

#include <cmath>
#include <limits>
#include <type_traits>

#include "contracttype.h"
#include "valueratio.h"
#include "../functional/plustype.h"
#include "../numeric/gcdvalue.h"
#include "../numeric/zero.h"
#include "../utility/typeidentity.h"

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct plusType<valueRatio<Type, Sign, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, Sign, Numerator, Denominator> > {};

 template <class Type, char Sign1, typename std :: make_unsigned <Type> :: type Numerator1, typename std :: make_unsigned <Type> :: type Denominator1, char Sign2, typename std :: make_unsigned <Type> :: type Numerator2, typename std :: make_unsigned <Type> :: type Denominator2>
	 struct plusType<valueRatio<Type, Sign1, Numerator1, Denominator1>, valueRatio<Type, Sign2, Numerator2, Denominator2> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type;
  //Common denominator
  constexpr static valueType denGCD = gcdValue <typename std :: make_unsigned <Type> :: type, Denominator1, Denominator2> :: value;
  constexpr static valueType denPart1 = ((Denominator1 > Denominator2) ? Denominator1 : Denominator2) / denGCD;
  constexpr static valueType denPart2 = (Denominator1 > Denominator2) ? Denominator2 : Denominator1;
  constexpr static valueType part1IntScale = Denominator2 / denGCD;
  constexpr static valueType part2IntScale = Denominator1 / denGCD;
  constexpr static valueType max = std :: numeric_limits <valueType> :: max();
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static const bool denOverFlow = (denPart2 > (max / denPart1));
  constexpr static const bool num1ExtOverFlow = (Numerator1 > zero <valueType> :: value) ? (part1IntScale > (max / Numerator1)) : false;
  constexpr static const bool num2ExtOverFlow = (Numerator2 > zero <valueType> :: value) ? (part2IntScale > (max / Numerator2)) : false;
  constexpr static scaleType denScale = denOverFlow ? ((static_cast<scaleType>(max) / static_cast<scaleType>(denPart1)) / (static_cast<scaleType>(denPart2))) : infinity;
  constexpr static scaleType num1ExtScale = num1ExtOverFlow ? (static_cast<scaleType>(max) / static_cast<scaleType>(Numerator1)) / static_cast<scaleType>(part1IntScale) : infinity;
  constexpr static scaleType num2ExtScale = num2ExtOverFlow ? (static_cast<scaleType>(max) / static_cast<scaleType>(Numerator2)) / static_cast<scaleType>(part2IntScale) : infinity;
  constexpr static const bool needScaleExt = denOverFlow || num1ExtOverFlow || num2ExtOverFlow;
  constexpr static scaleType minExt1 = (denScale < num1ExtScale) ? denScale : num1ExtScale;
  constexpr static scaleType scaleExt = (num2ExtScale < minExt1) ? num2ExtScale : minExt1;
  constexpr static scaleType denFloat = needScaleExt ? (scaleExt * static_cast<scaleType>(denPart1) * static_cast<scaleType>(denPart2)) : static_cast<scaleType>(denPart1 * denPart2);
  constexpr static scaleType num1Float = needScaleExt ? (scaleExt * static_cast<scaleType>(Numerator1) * static_cast<scaleType>(part1IntScale)) : static_cast<scaleType>(Numerator1 * static_cast<valueType>(part1IntScale));//Is it ok?
  constexpr static scaleType num2Float = needScaleExt ? (scaleExt * static_cast<scaleType>(Numerator2) * static_cast<scaleType>(part2IntScale)) : static_cast<scaleType>(Numerator2 * static_cast<valueType>(part2IntScale));//Is it ok?
  constexpr static valueType denominatorExt = needScaleExt ? static_cast<valueType>(denFloat) : (denPart1 * denPart2);
  constexpr static valueType numerator1 = needScaleExt ? (static_cast<valueType>(num1Float)) : (Numerator1 * part1IntScale);
  constexpr static valueType numerator2 = needScaleExt ? (static_cast<valueType>(num2Float)) : (Numerator2 * part2IntScale);
  //Addition
  constexpr static const bool needScale = (Sign1 == Sign2) ? (numerator1 > (max - numerator2)) : false;
  constexpr static scaleType scale = needScale ? (1.0l / (num1Float / static_cast<scaleType>(max) + (num2Float / static_cast<scaleType>(max)))) : infinity;
  constexpr static scaleType scaledDenominator = needScale ? (scale * denFloat) : static_cast<scaleType>(denominatorExt);
  constexpr static valueType numeratorSum = needScale ? (static_cast<valueType>((scale * num1Float) + (scale * num2Float))) : (numerator1 + numerator2);
  constexpr static valueType numeratorDiff = (numerator1 < numerator2) ? (numerator2 - numerator1) : (numerator1 - numerator2);
  constexpr static valueType numerator = (Sign1 == Sign2) ? numeratorSum : numeratorDiff;
  //Sign calculation
  constexpr static const char sign1 = ((Sign1 == '+') && (Sign2 == '-')) ? ((numerator1 < numerator2) ? '-' : '+') : Sign1;
  constexpr static const char sign = ((Sign1 == '-') && (Sign2 == '+')) ? ((numerator1 > numerator2) ? '-' : '+') : sign1;
  constexpr static valueType denominator = needScale ? static_cast<valueType>((scaledDenominator < 1.0) ? 1.0 : scaledDenominator) : denominatorExt;
  public:
  using type = typename contractType <valueRatio<Type, sign, numerator, denominator> > :: type;
 };

 template <class Type, char ... Signs, typename std :: make_unsigned <Type> :: type ... Numerators, typename std :: make_unsigned <Type> :: type ... Denominators>
	 struct plusType<valueRatio<Type, Signs, Numerators, Denominators>...>
	 : reduceType<plusType, valueRatio<Type, Signs, Numerators, Denominators>...> {};

 template <class Type1, class Type2, char Sign1, typename std :: make_unsigned <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, char Sign2, typename std :: make_unsigned <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
	 struct plusType<valueRatio<Type1, Sign1, Numerator1, Denominator1>, valueRatio<Type2, Sign2, Numerator2, Denominator2> >
	 : plusType<
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, Sign1, static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator1), static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator1)>,
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, Sign2, static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator2), static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator2)> >
	 {};
}

template <class Type1, class Type2, char Sign1, typename std :: make_unsigned <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, char Sign2, typename std :: make_unsigned <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
inline constexpr typename crap :: plusType <crap :: valueRatio<Type1, Sign1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Sign2, Numerator2, Denominator2> > :: type
operator + (crap :: valueRatio<Type1, Sign1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Sign2, Numerator2, Denominator2> ) noexcept
{
 return {};
}
#endif
