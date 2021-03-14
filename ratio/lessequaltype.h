#ifndef CRAP_RATIO_LESSEQUALTYPE
#define CRAP_RATIO_LESSEQUALTYPE

#include <cmath>
#include <limits>
#include <type_traits>

#include "valueratio.h"
#include "../functional/lessequaltype.h"
#include "../numeric/gcdvalue.h"
#include "../numeric/zero.h"

namespace crap
{
 template <class Type, typename std :: make_signed <Type> :: type Numerator1, typename std :: make_unsigned <Type> :: type Denominator1, typename std :: make_signed <Type> :: type Numerator2, typename std :: make_unsigned <Type> :: type Denominator2>
	 struct lessEqualType<valueRatio<Type, Numerator1, Denominator1>, valueRatio<Type, Numerator2, Denominator2> >
 {
  private:
  using scaleType = const long double;
  using numeratorType = typename std :: add_const <typename std :: make_signed <Type> :: type> :: type;
  using denominatorType = typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type;
  constexpr static denominatorType denGCD = gcdValue <denominatorType, Denominator1, Denominator2> :: value;
  constexpr static denominatorType part1IntScale = Denominator2 / denGCD;
  constexpr static denominatorType part2IntScale = Denominator1 / denGCD;
  constexpr static numeratorType numMax = std :: numeric_limits <numeratorType> :: max();
  constexpr static numeratorType numMin = std :: numeric_limits <numeratorType> :: min();
  constexpr static const bool num1ExtOverFlow = (Numerator1 > zero <numeratorType> :: value) && (part1IntScale > static_cast<denominatorType>(numMax / Numerator1));
  constexpr static const bool num2ExtOverFlow = (Numerator2 > zero <numeratorType> :: value) && (part2IntScale > static_cast<denominatorType>(numMax / Numerator2));
  constexpr static const bool num1ExtUnderFlow = (Numerator1 < zero <numeratorType> :: value) && (part1IntScale > static_cast<denominatorType>(numMin / Numerator1));
  constexpr static const bool num2ExtUnderFlow = (Numerator2 < zero <numeratorType> :: value) && (part2IntScale > static_cast<denominatorType>(numMin / Numerator2));
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType num1ExtOverScale = num1ExtOverFlow ? std :: abs((static_cast<scaleType>(numMax) / static_cast<scaleType>(Numerator1)) / static_cast<scaleType>(part1IntScale)) : infinity;
  constexpr static scaleType num2ExtOverScale = num2ExtOverFlow ? std :: abs((static_cast<scaleType>(numMax) / static_cast<scaleType>(Numerator2)) / static_cast<scaleType>(part2IntScale)) : infinity;
  constexpr static scaleType num1ExtUnderScale = num1ExtUnderFlow ? std :: abs((static_cast<scaleType>(numMin) / static_cast<scaleType>(Numerator1)) / static_cast<scaleType>(part1IntScale)) : infinity;
  constexpr static scaleType num2ExtUnderScale = num2ExtUnderFlow ? std :: abs((static_cast<scaleType>(numMin) / static_cast<scaleType>(Numerator2)) / static_cast<scaleType>(part2IntScale)) : infinity;
  constexpr static const bool needScaleExt = num1ExtOverFlow || num2ExtOverFlow || num1ExtUnderFlow || num2ExtUnderFlow;
  constexpr static scaleType minExt1 = (num2ExtOverScale < num1ExtOverScale) ? num2ExtOverScale : num1ExtOverScale;
  constexpr static scaleType minExt2 = (num1ExtUnderScale < minExt1) ? num1ExtUnderScale : minExt1;
  constexpr static scaleType scaleExt = (num2ExtUnderScale < minExt2) ? num2ExtUnderScale : minExt2;
  constexpr static numeratorType numerator1 = needScaleExt ? (static_cast<numeratorType>(scaleExt * static_cast<scaleType>(Numerator1) * static_cast<scaleType>(part1IntScale))) : (Numerator1 * part1IntScale);
  constexpr static numeratorType numerator2 = needScaleExt ? (static_cast<numeratorType>(scaleExt * static_cast<scaleType>(Numerator2) * static_cast<scaleType>(part2IntScale))) : (Numerator2 * part2IntScale);
  constexpr static const bool numUnderFlow = (numerator1 > zero <numeratorType> :: value) && (numerator2 < (numMin + numerator1));
  constexpr static const bool numOverFlow = (numerator1 < zero <numeratorType> :: value) && (numerator2 > (numMax + numerator1));
  public:
  constexpr static const bool value = (!numUnderFlow) && (numerator1 <= numerator2) || numOverFlow;
 };
 
 template <class Type1, class Type2, typename std :: make_signed <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, typename std :: make_signed <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
	 struct lessEqualType<valueRatio<Type1, Numerator1, Denominator1>, valueRatio<Type2, Numerator2, Denominator2> >
	 : lessEqualType<
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, static_cast<typename std :: make_signed <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator1), static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator1)>,
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, static_cast<typename std :: make_signed <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator2), static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator2)> >
	 {};
}

template <class Type1, class Type2, typename std :: make_signed <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, typename std :: make_signed <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
inline constexpr bool operator <= (crap :: valueRatio<Type1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Numerator2, Denominator2> ) noexcept
{
 return crap :: lessEqualType <crap :: valueRatio<Type1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Numerator2, Denominator2> > :: value;
}
#endif

