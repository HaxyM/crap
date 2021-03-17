#ifndef CRAP_RATIO_MULTIPLIESTYPE
#define CRAP_RATIO_MULTIPLIESTYPE

#include <cmath>
#include <limits>
#include <type_traits>

#include "contracttype.h"
#include "valueratio.h"
#include "../functional/multipliestype.h"
#include "../utility/typeidentity.h"

namespace crap
{
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct multipliesType<valueRatio<Type, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, Numerator, Denominator> > {};

 template <class Type, typename std :: make_signed <Type> :: type Numerator1, typename std :: make_unsigned <Type> :: type Denominator1, typename std :: make_signed <Type> :: type Numerator2, typename std :: make_unsigned <Type> :: type Denominator2>
	 struct multipliesType<valueRatio<Type, Numerator1, Denominator1>, valueRatio<Type, Numerator2, Denominator2> >
 {
  private:
  using scaleType = const long double;
  using numeratorType = typename std :: add_const <typename std :: make_signed <Type> :: type> :: type;
  using denominatorType = typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type;
  constexpr static numeratorType minusOne = -(identity <numeratorType> :: value);
  constexpr static numeratorType numMax = std :: numeric_limits <numeratorType> :: max();
  constexpr static numeratorType numMin = std :: numeric_limits <numeratorType> :: min();
  constexpr static denominatorType denMax = std :: numeric_limits <denominatorType> :: max();
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static numeratorType contractedNum1 = contractType <valueRatio<Type, Numerator1, Denominator2> > :: type :: num;
  constexpr static numeratorType contractedNum2 = contractType <valueRatio<Type, Numerator2, Denominator1> > :: type :: num;
  constexpr static denominatorType contractedDen1 = contractType <valueRatio<Type, Numerator2, Denominator1> > :: type :: den;
  constexpr static denominatorType contractedDen2 = contractType <valueRatio<Type, Numerator1, Denominator2> > :: type :: den;
  constexpr const static bool numOverflow1 = (contractedNum1 > zero <numeratorType> :: value) && (contractedNum2 > zero <numeratorType> :: value) && (contractedNum2 > (numMax / contractedNum1));
  constexpr const static bool numOverflow2 = (contractedNum1 == minusOne) && (contractedNum2 < zero <numeratorType> :: value) && (zero <numeratorType> :: value > (numMax + contractedNum2));
  constexpr const static bool numOverflow3 = (contractedNum1 < minusOne) && (contractedNum2 < zero <numeratorType> :: value) && (contractedNum2 < (numMax / contractedNum1));
  constexpr const static bool numUnderflow1 = (contractedNum1 > zero <numeratorType> :: value) && (contractedNum2 < zero <numeratorType> :: value) && (contractedNum2 < (numMin / contractedNum1));
  constexpr const static bool numUnderflow2 = (contractedNum1 == minusOne) && (contractedNum2 > zero <numeratorType> :: value) && (zero <numeratorType> :: value < (numMin + contractedNum2));
  constexpr const static bool numUnderflow3 = (contractedNum1 < minusOne) && (contractedNum2 > zero <numeratorType> :: value) && (contractedNum2 > (numMin / contractedNum1));
  constexpr const static bool denOverflow = contractedDen2 > (denMax / contractedDen1);
  constexpr const static bool needScale = numOverflow1 || numOverflow2 || numOverflow3 || numUnderflow1 || numUnderflow2 || numUnderflow3 || denOverflow;
  constexpr static scaleType numOverflowScale = (numOverflow1 || numOverflow2 || numOverflow3) ? (static_cast<scaleType>(numMax) / static_cast<scaleType>(contractedNum1) / static_cast<scaleType>(contractedNum2)) : infinity;
  constexpr static scaleType numUnderflowScale = (numUnderflow1 || numUnderflow2 || numUnderflow3) ? (static_cast<scaleType>(numMin) / static_cast<scaleType>(contractedNum1) / static_cast<scaleType>(contractedNum2)) : infinity;
  constexpr static scaleType denOverflowScale = denOverflow ? (static_cast<scaleType>(denMax) / static_cast<scaleType>(contractedDen1) / static_cast<scaleType>(contractedDen2)) : infinity;
  constexpr static scaleType scaleCandidate1 = (numOverflowScale < numUnderflowScale) ? numOverflowScale : numUnderflowScale;
  constexpr static scaleType scale = (scaleCandidate1 < denOverflowScale) ? scaleCandidate1 : denOverflowScale;
  constexpr static scaleType scaledDenominator = needScale ? (scale * static_cast<scaleType>(contractedDen1) * static_cast<scaleType>(contractedDen2)) : static_cast<scaleType>(contractedDen1 * contractedDen2);
  constexpr static numeratorType numerator = needScale ? static_cast<numeratorType>(scale * static_cast<scaleType>(contractedNum1) * static_cast<scaleType>(contractedNum2)) : (contractedNum1 * contractedNum2);
  constexpr static denominatorType denominator = needScale ? static_cast<denominatorType>((scaledDenominator < 1.0) ? 1.0 : scaledDenominator) : (contractedDen1 * contractedDen2);
  public:
  using type = typename contractType <valueRatio<Type, numerator, denominator> > :: type; //TODO: Consider contracting optional on overflow.
 };

 template <class Type, typename std :: make_signed <Type> :: type ... Numerators, typename std :: make_unsigned <Type> :: type ... Denominators>
	 struct multipliesType<valueRatio<Type, Numerators, Denominators>...>
	 : reduceType<multipliesType, valueRatio<Type, Numerators, Denominators>...> {};

 template <class Type1, class Type2, typename std :: make_signed <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, typename std :: make_signed <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
	 struct multipliesType<valueRatio<Type1, Numerator1, Denominator1>, valueRatio<Type2, Numerator2, Denominator2> >
	 : multipliesType<
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, static_cast<typename std :: make_signed <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator1), static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator1)>,
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, static_cast<typename std :: make_signed <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator2), static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator2)> >
	 {};
}

template <class Type1, class Type2, typename std :: make_signed <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, typename std :: make_signed <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
inline constexpr typename crap :: multipliesType <crap :: valueRatio<Type1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Numerator2, Denominator2> > :: type
operator * (crap :: valueRatio<Type1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Numerator2, Denominator2> ) noexcept
{
 return {};
}
#endif

