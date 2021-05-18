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
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct plusType<valueRatio<Type, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, Numerator, Denominator> > {};

 template <class Type, typename std :: make_signed <Type> :: type Numerator1, typename std :: make_unsigned <Type> :: type Denominator1, typename std :: make_signed <Type> :: type Numerator2, typename std :: make_unsigned <Type> :: type Denominator2>
	 struct plusType<valueRatio<Type, Numerator1, Denominator1>, valueRatio<Type, Numerator2, Denominator2> >
 {
  private:
  using scaleType = const long double;
  using numeratorType = typename std :: add_const <typename std :: make_signed <Type> :: type> :: type;
  using denominatorType = typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type;
  constexpr static denominatorType denGCD = gcdValue <denominatorType, Denominator1, Denominator2> :: value;
  constexpr static denominatorType denPart1 = ((Denominator1 > Denominator2) ? Denominator1 : Denominator2) / denGCD;
  constexpr static denominatorType denPart2 = (Denominator1 > Denominator2) ? Denominator2 : Denominator1;
  constexpr static denominatorType part1IntScale = Denominator2 / denGCD;
  constexpr static denominatorType part2IntScale = Denominator1 / denGCD;
  constexpr static denominatorType denMax = std :: numeric_limits <denominatorType> :: max();
  constexpr static numeratorType numMax = std :: numeric_limits <numeratorType> :: max();
  constexpr static numeratorType numMin = std :: numeric_limits <numeratorType> :: min();
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static const bool denOverFlow = (denPart2 > (denMax / denPart1));
  constexpr static const bool num1ExtOverFlow = (Numerator1 > zero <numeratorType> :: value) && (part1IntScale > static_cast<denominatorType>(numMax / Numerator1));
  constexpr static const bool num2ExtOverFlow = (Numerator2 > zero <numeratorType> :: value) && (part2IntScale > static_cast<denominatorType>(numMax / Numerator2));
  constexpr static const bool num1ExtUnderFlow = (Numerator1 < zero <numeratorType> :: value) && (part1IntScale > static_cast<denominatorType>(numMin / Numerator1));
  constexpr static const bool num2ExtUnderFlow = (Numerator2 < zero <numeratorType> :: value) && (part2IntScale > static_cast<denominatorType>(numMin / Numerator2));
  constexpr static scaleType denScale = denOverFlow ? ((static_cast<scaleType>(denMax) / static_cast<scaleType>(denPart1)) / (static_cast<scaleType>(denPart2))) : infinity;
  constexpr static scaleType num1ExtOverScale = num1ExtOverFlow ? std :: abs((static_cast<scaleType>(numMax) / static_cast<scaleType>(Numerator1)) / static_cast<scaleType>(part1IntScale)) : infinity;
  constexpr static scaleType num2ExtOverScale = num2ExtOverFlow ? std :: abs((static_cast<scaleType>(numMax) / static_cast<scaleType>(Numerator2)) / static_cast<scaleType>(part2IntScale)) : infinity;
  constexpr static scaleType num1ExtUnderScale = num1ExtUnderFlow ? std :: abs((static_cast<scaleType>(numMin) / static_cast<scaleType>(Numerator1)) / static_cast<scaleType>(part1IntScale)) : infinity;
  constexpr static scaleType num2ExtUnderScale = num2ExtUnderFlow ? std :: abs((static_cast<scaleType>(numMin) / static_cast<scaleType>(Numerator2)) / static_cast<scaleType>(part2IntScale)) : infinity;
  constexpr static const bool needScaleExt = denOverFlow || num1ExtOverFlow || num2ExtOverFlow || num1ExtUnderFlow || num2ExtUnderFlow;
  constexpr static scaleType minExt1 = (denScale < num1ExtOverScale) ? denScale : num1ExtOverScale;
  constexpr static scaleType minExt2 = (num2ExtOverScale < minExt1) ? num2ExtOverScale : minExt1;
  constexpr static scaleType minExt3 = (num1ExtUnderScale < minExt2) ? num1ExtUnderScale : minExt2;
  constexpr static scaleType scaleExt = (num2ExtUnderScale < minExt3) ? num2ExtUnderScale : minExt3;
  constexpr static scaleType denFloat = needScaleExt ? (scaleExt * static_cast<scaleType>(denPart1) * static_cast<scaleType>(denPart2)) : static_cast<scaleType>(denPart1 * denPart2);
  constexpr static scaleType num1Float = needScaleExt ? (scaleExt * static_cast<scaleType>(Numerator1) * static_cast<scaleType>(part1IntScale)) : static_cast<scaleType>(Numerator1 * static_cast<numeratorType>(part1IntScale));//Is it ok?
  constexpr static scaleType num2Float = needScaleExt ? (scaleExt * static_cast<scaleType>(Numerator2) * static_cast<scaleType>(part2IntScale)) : static_cast<scaleType>(Numerator2 * static_cast<numeratorType>(part2IntScale));//Is it ok?
  constexpr static denominatorType denominatorExt = needScaleExt ? static_cast<denominatorType>(denFloat) : (denPart1 * denPart2);
  constexpr static numeratorType numerator1 = needScaleExt ? (static_cast<numeratorType>(num1Float)) : (Numerator1 * part1IntScale);
  constexpr static numeratorType numerator2 = needScaleExt ? (static_cast<numeratorType>(num2Float)) : (Numerator2 * part2IntScale);
  constexpr static const bool numOverFlow = (numerator1 > zero <numeratorType> :: value) ? (numerator2 > (numMax - numerator1)) : false;
  constexpr static const bool numUnderFlow = (numerator1 < zero <numeratorType> :: value) ? (numerator2 < (numMin - numerator1)) : false;
  constexpr static scaleType numOverScale = numOverFlow ? std :: abs(1.0l / (num1Float / static_cast<scaleType>(numMax) + (num2Float / static_cast<scaleType>(numMax)))) : infinity;
  constexpr static scaleType numUnderScale = numUnderFlow ? std :: abs(1.0l / (num1Float / static_cast<scaleType>(numMin) + (num2Float / static_cast<scaleType>(numMin)))) : infinity;
  constexpr static scaleType scale = (numOverScale < numUnderScale) ? numOverScale : numUnderScale;
  constexpr static const bool needScale = (numOverFlow || numUnderFlow);
  constexpr static numeratorType numerator = needScale ? (static_cast<numeratorType>((scale * num1Float) + (scale * num2Float))) : (numerator1 + numerator2);
  constexpr static denominatorType denominator = needScale ? (static_cast<denominatorType>(scale * denFloat)) : denominatorExt;
  public:
  using type = typename contractType <valueRatio<Type, numerator, denominator> > :: type;
 };

 template <class Type, typename std :: make_signed <Type> :: type ... Numerators, typename std :: make_unsigned <Type> :: type ... Denominators>
	 struct plusType<valueRatio<Type, Numerators, Denominators>...>
	 : reduceType<plusType, valueRatio<Type, Numerators, Denominators>...> {};

 template <class Type1, class Type2, typename std :: make_signed <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, typename std :: make_signed <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
	 struct plusType<valueRatio<Type1, Numerator1, Denominator1>, valueRatio<Type2, Numerator2, Denominator2> >
	 : plusType<
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, static_cast<typename std :: make_signed <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator1), static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator1)>,
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, static_cast<typename std :: make_signed <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator2), static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator2)> >
	 {};
}

template <class Type1, class Type2, typename std :: make_signed <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, typename std :: make_signed <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
inline constexpr typename crap :: plusType <crap :: valueRatio<Type1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Numerator2, Denominator2> > :: type
operator + (crap :: valueRatio<Type1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Numerator2, Denominator2> ) noexcept
{
 return {};
}
#endif

