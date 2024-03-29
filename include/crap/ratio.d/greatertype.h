#ifndef CRAP_RATIO_GRATERTYPE
#define CRAP_RATIO_GRATERTYPE

#include <cmath>
#include <limits>
#include <type_traits>

#include "valueratio.h"
#include "../functional.d/greatertype.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/gcdvalue.h"

namespace crap
{
 template <class Type, char Sign1, Type Numerator1, Type Denominator1, char Sign2, Type Numerator2, Type Denominator2>
	 struct greaterType<valueRatio<Type, Sign1, Numerator1, Denominator1>, valueRatio<Type, Sign2, Numerator2, Denominator2> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const <Type> :: type;
  //Common denominator
  constexpr static valueType denGCD = gcdValue <Type, Denominator1, Denominator2> :: value;
  constexpr static valueType denPart1 = ((Denominator1 > Denominator2) ? Denominator1 : Denominator2) / denGCD;
  constexpr static valueType denPart2 = (Denominator1 > Denominator2) ? Denominator2 : Denominator1;
  constexpr static valueType part1IntScale = Denominator2 / denGCD;
  constexpr static valueType part2IntScale = Denominator1 / denGCD;
  constexpr static valueType max = std :: numeric_limits <valueType> :: max();
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static const bool num1ExtOverFlow = (Numerator1 > zero <valueType> :: value) ? (part1IntScale > (max / Numerator1)) : false;
  constexpr static const bool num2ExtOverFlow = (Numerator2 > zero <valueType> :: value) ? (part2IntScale > (max / Numerator2)) : false;
  constexpr static scaleType num1ExtScale = num1ExtOverFlow ? (static_cast<scaleType>(max) / static_cast<scaleType>(Numerator1)) / static_cast<scaleType>(part1IntScale) : infinity;
  constexpr static scaleType num2ExtScale = num2ExtOverFlow ? (static_cast<scaleType>(max) / static_cast<scaleType>(Numerator2)) / static_cast<scaleType>(part2IntScale) : infinity;
  constexpr static const bool needScaleExt = num1ExtOverFlow || num2ExtOverFlow;
  constexpr static scaleType scaleExt = (num2ExtScale < num1ExtScale) ? num2ExtScale : num1ExtScale;
  constexpr static scaleType num1Float = needScaleExt ? (scaleExt * static_cast<scaleType>(Numerator1) * static_cast<scaleType>(part1IntScale)) : static_cast<scaleType>(Numerator1 * static_cast<valueType>(part1IntScale));//Is it ok?
  constexpr static scaleType num2Float = needScaleExt ? (scaleExt * static_cast<scaleType>(Numerator2) * static_cast<scaleType>(part2IntScale)) : static_cast<scaleType>(Numerator2 * static_cast<valueType>(part2IntScale));//Is it ok?
  constexpr static valueType numerator1 = needScaleExt ? (static_cast<valueType>(num1Float)) : (Numerator1 * part1IntScale);
  constexpr static valueType numerator2 = needScaleExt ? (static_cast<valueType>(num2Float)) : (Numerator2 * part2IntScale);
  //Sign calculation
  constexpr static const bool value1 = ((Sign1 == '+') && (Sign2 == '+')) ? (numerator1 > numerator2) : (Sign1 == '+');
  public:
  constexpr static const bool value = ((Sign1 == '-') && (Sign2 == '-')) ? (numerator1 < numerator2) : value1;
 };
 
 template <class Type1, class Type2, char Sign1, Type1 Numerator1, Type1 Denominator1, char Sign2, Type2 Numerator2, Type2 Denominator2>
	 struct greaterType<valueRatio<Type1, Sign1, Numerator1, Denominator1>, valueRatio<Type2, Sign2, Numerator2, Denominator2> >
	 : greaterType<
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, Sign1, static_cast<typename std :: common_type <Type1, Type2> :: type>(Numerator1), static_cast<typename std :: common_type <Type1, Type2> :: type>(Denominator1)>,
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, Sign2, static_cast<typename std :: common_type <Type1, Type2> :: type>(Numerator2), static_cast<typename std :: common_type <Type1, Type2> :: type>(Denominator2)> >
	 {};
}

template <class Type1, class Type2, char Sign1, Type1 Numerator1, Type1 Denominator1, char Sign2, Type2 Numerator2, Type2 Denominator2>
inline constexpr bool operator > (crap :: valueRatio<Type1, Sign1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Sign2, Numerator2, Denominator2> ) noexcept
{
 return crap :: greaterType <crap :: valueRatio<Type1, Sign1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Sign2, Numerator2, Denominator2> > :: value;
}
#endif
