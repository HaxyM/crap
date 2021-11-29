#ifndef CRAP_RATIO_DIVIDESTYPE
#define CRAP_RATIO_DIVIDESTYPE

#include <cmath>
#include <limits>
#include <type_traits>

#include "contracttype.h"
#include "valueratio.h"
#include "../functional/dividestype.h"
#include "../numeric/accumulatetype.h"
#include "../numeric/identity.h"
#include "../utility/typeidentity.h"

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct dividesType<valueRatio<Type, Sign, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, Sign, Numerator, Denominator> > {};

 template <class Type, char Sign1, typename std :: make_unsigned <Type> :: type Numerator1, typename std :: make_unsigned <Type> :: type Denominator1, char Sign2, typename std :: make_unsigned <Type> :: type Numerator2, typename std :: make_unsigned <Type> :: type Denominator2>
 struct dividesType<valueRatio<Type, Sign1, Numerator1, Denominator1>, valueRatio<Type, Sign2, Numerator2, Denominator2> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type;
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static valueType max = std :: numeric_limits <valueType> :: max();
  constexpr const static char sign = (Sign1 == Sign2) ? '+' : '-';
  using contracted1 = typename contractType <valueRatio<Type, Sign1, Numerator1, Numerator2> > :: type;
  using contracted2 = typename contractType <valueRatio<Type, Sign2, Denominator2, Denominator1> > :: type;
  constexpr const static bool numOverflow = (contracted1 :: num > (max / contracted2 :: num));
  constexpr const static bool denOverflow = (contracted1 :: den > (max / contracted2 :: den));
  constexpr const static bool needScale = (numOverflow || denOverflow);
  constexpr static scaleType numOverflowScale = numOverflow ? (static_cast<scaleType>(max) / static_cast<scaleType>(contracted1 :: num) / static_cast<scaleType>(contracted2 :: num)) : infinity;
  constexpr static scaleType denOverflowScale = denOverflow ? (static_cast<scaleType>(max) / static_cast<scaleType>(contracted1 :: den) / static_cast<scaleType>(contracted2 :: den)) : infinity;
  constexpr static scaleType scale = (numOverflowScale < denOverflowScale) ? numOverflowScale : denOverflowScale;
  constexpr static scaleType scaledDenominator = needScale ? (scale * static_cast<scaleType>(contracted1 :: den) * static_cast<scaleType>(contracted2 :: den)) : static_cast<scaleType>(contracted1 :: den * contracted2 :: den);
  constexpr static valueType numerator = needScale ? static_cast<valueType>(scale * static_cast<scaleType>(contracted1 :: num) * static_cast<scaleType>(contracted2 :: num)) : (contracted1 :: num * contracted2 :: num);
  constexpr static valueType scaledDenominatorInRange = (scaledDenominator < 1.0) ? identity <valueType> :: value : ((scaledDenominator > static_cast<scaleType>(max) ? max : static_cast<valueType>(scaledDenominator)));
  constexpr static valueType denominator = needScale ? scaledDenominatorInRange : (contracted1 :: den * contracted2 :: den);
  public:
  using type = typename contractType <valueRatio<Type, sign, numerator, denominator> > :: type; //TODO: Consider contracting optional on overflow.
 };

 template <class Type, char ... Signs, typename std :: make_unsigned <Type> :: type ... Numerators, typename std :: make_unsigned <Type> :: type ... Denominators>
	 struct dividesType<valueRatio<Type, Signs, Numerators, Denominators>...>
	 : accumulateType<dividesType, valueRatio<Type, Signs, Numerators, Denominators>...> {};

 template <class Type1, class Type2, char Sign1, typename std :: make_unsigned <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, char Sign2, typename std :: make_unsigned <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
	 struct dividesType<valueRatio<Type1, Sign1, Numerator1, Denominator1>, valueRatio<Type2, Sign2, Numerator2, Denominator2> >
	 : dividesType<
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, Sign1, static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator1), static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator1)>,
	 valueRatio<typename std :: common_type <Type1, Type2> :: type, Sign2, static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator2), static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator2)> >
	 {};
}

template <class Type1, class Type2, char Sign1, typename std :: make_unsigned <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, char Sign2, typename std :: make_unsigned <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
inline constexpr typename crap :: dividesType <crap :: valueRatio<Type1, Sign1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Sign2, Numerator2, Denominator2> > :: type
operator / (crap :: valueRatio<Type1, Sign1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Sign2, Numerator2, Denominator2> ) noexcept
{
 return {};
}
#endif
