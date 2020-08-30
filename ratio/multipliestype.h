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
  using contraction1 = typename contractType <valueRatio<Type, Numerator1, Denominator2> > :: type;
  using contraction2 = typename contractType <valueRatio<Type, Numerator2, Denominator1> > :: type;
  constexpr static numeratorType contraction1Num = contraction1 :: num;
  constexpr static numeratorType contraction2Num = contraction2 :: num;
  constexpr static denominatorType contraction1Den = contraction1 :: den;
  constexpr static denominatorType contraction2Den = contraction2 :: den;
  constexpr static numeratorType numMin = std :: numeric_limits <numeratorType> :: min();
  constexpr static numeratorType numMax = std :: numeric_limits <numeratorType> :: max();
  constexpr static denominatorType denMax = std :: numeric_limits <denominatorType> :: max();
  constexpr const static bool numUnderflow = (((contraction1Num != zero <numeratorType> :: value) && (contraction1Num != -(identity <numeratorType> :: value))) ? ((contraction1Num < zero <numeratorType> :: value) ? (contraction2Num > (numMin / contraction1Num)) : (contraction2Num < (numMin / contraction1Num))) : false);
  constexpr static const bool numOverflow = ((contraction1Num != zero <numeratorType> :: value) ? ((contraction1Num < zero <numeratorType> :: value) ? (contraction2Num < (numMax / contraction1Num)) : (contraction2Num > (numMax / contraction1Num))) : false);
  constexpr static const bool denOverflow = ((contraction1Den != zero <denominatorType> :: value) ? (contraction2Den > (denMax / contraction1Den)) : false);
  constexpr static const bool needScale = (numUnderflow || numOverflow || denOverflow);
  constexpr static scaleType numUnderScale = (numUnderflow ? std :: abs(((static_cast<scaleType>(numMin)) / (static_cast<scaleType>(contraction1Num))) / (static_cast<scaleType>(contraction2Num))) : 1.0l);
  constexpr static scaleType numOverScale = (numOverflow ? std :: abs(((static_cast<scaleType>(numMax)) / (static_cast<scaleType>(contraction1Num))) / ((const long double)(contraction2Num))) : 1.0l);
  constexpr static scaleType denScale = (denOverflow ? (((static_cast<scaleType>(denMax)) / (static_cast<scaleType>(contraction1Den))) / (static_cast<scaleType>(contraction2Den))) : 1.0l);
  constexpr static scaleType scale = ((numUnderScale < numOverScale) ? ((numUnderScale < denScale) ? numUnderScale : denScale) : ((numOverScale < denScale) ? numOverScale : denScale));
  constexpr static scaleType contr1FloatNum = (static_cast<scaleType>((contraction1Num > contraction2Num) ? contraction1Num : contraction2Num));
  constexpr static scaleType contr2FloatNum = (static_cast<scaleType>((contraction1Num > contraction2Num) ? contraction2Num : contraction1Num));
  constexpr static scaleType contr1FloatDen = (static_cast<scaleType>((contraction1Den > contraction2Den) ? contraction1Den : contraction2Den));
  constexpr static scaleType contr2FloatDen = (static_cast<scaleType>((contraction1Den > contraction2Den) ? contraction2Den : contraction1Den));
  constexpr static numeratorType finNum = (needScale ? (static_cast<numeratorType>((scale * contr1FloatNum) * contr2FloatNum)) : (contraction1Num * contraction2Num));
  constexpr static denominatorType finDen = (needScale ? (static_cast<denominatorType>((scale * contr1FloatDen) * contr2FloatDen)) : (contraction1Den * contraction2Den));
  public:
  using type = typename contractType <valueRatio<Type,finNum, finDen> > :: type; //TODO: Consider contracting optional on overflow.
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

