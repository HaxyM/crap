#ifndef CRAP_RATIO_DIVIDESTYPE
#define CRAP_RATIO_DIVIDESTYPE

#include "contracttype.h"
#include "valueratio.h"
#include "../functional/dividestype.h"
#include "../numeric/accumulatetype.h"
#include "../numeric/zero.h"

#include <cmath>
#include <limits>
#include <type_traits>

namespace crap
{
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct dividesType<valueRatio<Type, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, Numerator, Denominator> > {};

 template <class Type, typename std :: make_signed <Type> :: type Numerator1, typename std :: make_unsigned <Type> :: type Denominator1, typename std :: make_signed <Type> :: type Numerator2, typename std :: make_unsigned <Type> :: type Denominator2>
	 struct dividesType<valueRatio<Type, Numerator1, Denominator1>, valueRatio<Type, Numerator2, Denominator2> >
 {
  private:
  using scaleType = const long double;
  using numeratorType = typename std :: add_const <typename std :: make_signed <Type> :: type> :: type;
  using denominatorType = typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type;
  static_assert(Numerator2 != zero <numeratorType> :: value, "Division by zero");
  constexpr static numeratorType numerator1contracted = Numerator1 / (gcdValue <numeratorType,Numerator1, Numerator2> :: value);
  constexpr static numeratorType numerator2contracted = Numerator2 / (gcdValue <numeratorType,Numerator1, Numerator2> :: value);
  constexpr static denominatorType denominator1contracted = Denominator1 / (gcdValue <denominatorType,Denominator1, Denominator2> :: value);
  constexpr static denominatorType denominator2contracted = Denominator2 / (gcdValue <denominatorType,Denominator1, Denominator2> :: value);
  constexpr static numeratorType numerator2sign = (numerator2contracted < zero <numeratorType> :: value) ? static_cast<numeratorType>(-1) : static_cast<numeratorType>(1);
  constexpr const static bool numUnsignedOverflow = (numerator1contracted > zero <numeratorType> :: value) && (denominator2contracted > static_cast<denominatorType>(std :: numeric_limits<numeratorType> :: max() / numerator1contracted));
  constexpr const static bool numUnsignedUnderflow = (numerator1contracted < zero <numeratorType> :: value) && (denominator2contracted > static_cast<denominatorType>(std :: numeric_limits<numeratorType> :: min() / numerator1contracted));
  constexpr const static bool absOverflow = (numerator2contracted < zero <numeratorType> :: value) && (static_cast<numeratorType>(-1) < (std :: numeric_limits <numeratorType> :: max() / numerator2contracted));
  constexpr const static bool absUnderflow = (numerator1contracted > zero <numeratorType> :: value) && (static_cast<numeratorType>(-1) < (std :: numeric_limits <numeratorType> :: min() / numerator1contracted));
  constexpr static scaleType numUnsignedOverflowScale = numUnsignedOverflow ? std :: abs(static_cast<scaleType>(std :: numeric_limits <numeratorType> :: max()) / (static_cast<scaleType>(numerator1contracted) * static_cast<scaleType>(denominator2contracted))) : std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType numUnsignedUnderflowScale = numUnsignedUnderflow ? std :: abs(static_cast<scaleType>(std :: numeric_limits <numeratorType> :: min()) / (static_cast<scaleType>(numerator1contracted) * static_cast<scaleType>(denominator2contracted))) : std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType absOverflowScale = absOverflow ? std :: abs(static_cast<scaleType>(std :: numeric_limits <numeratorType> :: max() / (static_cast<scaleType>(numerator2sign) * static_cast<scaleType>(numerator2contracted)))) : std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType absUnderflowScale = absUnderflow ? std :: abs(static_cast<scaleType>(std :: numeric_limits <numeratorType> :: min() / (static_cast<scaleType>(numerator2sign) * static_cast<scaleType>(numerator1contracted)))) : std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType scale11 = (numUnsignedOverflowScale < numUnsignedUnderflowScale) ? numUnsignedOverflowScale : numUnsignedUnderflowScale;
  constexpr static scaleType scale12 = (scale11 < absOverflowScale) ? scale11 : absOverflowScale;
  constexpr static scaleType scale1 = (scale12 < absUnderflowScale) ? scale12 : absUnderflowScale;
  constexpr const static bool needScale1 = numUnsignedOverflow || numUnsignedUnderflow || absOverflow || absUnderflow;
  constexpr static scaleType numeratorUnsignedFloat = needScale1 ? (scale1 * static_cast<scaleType>(numerator1contracted) * static_cast<scaleType>(denominator2contracted)) : static_cast<scaleType>(numerator1contracted * denominator2contracted);
  constexpr static scaleType numerator2unsignedFloat = needScale1 ? (scale1 * static_cast<scaleType>(numerator2sign) * static_cast<numeratorType>(numerator2contracted)) : static_cast<scaleType>(numerator2sign * numerator2contracted);
  constexpr static numeratorType numeratorUnsigned = needScale1 ? static_cast<numeratorType>(numeratorUnsignedFloat) : static_cast<numeratorType>(numerator1contracted * denominator2contracted);
  constexpr static denominatorType numerator2unsigned = needScale1 ? static_cast<denominatorType>(numerator2unsignedFloat) : static_cast<denominatorType>(numerator2sign * numerator2contracted);
  constexpr const static bool numOverflowInt = (!needScale1) && (numeratorUnsigned < zero <numeratorType> :: value) && (numerator2sign < (std :: numeric_limits <numeratorType> :: max() / numeratorUnsigned));
  constexpr const static bool numUnderflowInt = (!needScale1) && (numeratorUnsigned > zero <numeratorType> :: value) && (numerator2sign < (std :: numeric_limits <numeratorType> :: min() / numeratorUnsigned));
  constexpr const static bool denOverflowInt = (!needScale1) && (numerator2unsigned > (std :: numeric_limits <denominatorType> :: max() / denominator1contracted));
  constexpr const static bool numOverflowFloat = (needScale1) && (numeratorUnsignedFloat < static_cast<scaleType>(zero <numeratorType> :: value)) && (static_cast<scaleType>(numerator2sign) < (static_cast<scaleType>(std :: numeric_limits <numeratorType> :: max()) / numeratorUnsignedFloat));
  constexpr const static bool numUnderflowFloat = (needScale1) && (numeratorUnsignedFloat > static_cast<scaleType>(zero <numeratorType> :: value)) && (static_cast<scaleType>(numerator2sign) < (static_cast<scaleType>(std :: numeric_limits <numeratorType> :: min()) / numeratorUnsignedFloat));
  constexpr const static bool denOverflowFloat = (needScale1) && (numerator2unsignedFloat > (static_cast<scaleType>(std :: numeric_limits <denominatorType> :: max()) / static_cast<scaleType>(denominator1contracted)));
  constexpr static scaleType numOverflowIntScale = numOverflowInt ? std :: abs(static_cast<scaleType>(std :: numeric_limits <numeratorType> :: max()) / (static_cast<scaleType>(numerator2sign) * static_cast<scaleType>(numeratorUnsigned))) : std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType numUnderflowIntScale = numUnderflowInt ? std :: abs(static_cast<scaleType>(std :: numeric_limits <numeratorType> :: min()) / (static_cast<scaleType>(numerator2sign) * static_cast<scaleType>(numeratorUnsigned))) : std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType denOverflowIntScale = denOverflowInt ? std :: abs(static_cast<scaleType>(std :: numeric_limits <denominatorType> :: max()) / (static_cast<scaleType>(denominator1contracted) * static_cast<scaleType>(numerator2unsigned))) : std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType numOverflowFloatScale = numOverflowFloat ? std :: abs(static_cast<scaleType>(std :: numeric_limits <numeratorType> :: max()) / (static_cast<scaleType>(numerator2sign) * numeratorUnsignedFloat)) : std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType numUnderflowFloatScale = numUnderflowFloat ? std :: abs(static_cast<scaleType>(std :: numeric_limits <numeratorType> :: min()) / (static_cast<scaleType>(numerator2sign) * numeratorUnsignedFloat)) : std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType denOverflowFloatScale = denOverflowFloat ? std :: abs(static_cast<scaleType>(std :: numeric_limits <denominatorType> :: max()) / (static_cast<scaleType>(denominator1contracted) * numerator2unsignedFloat)) : std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType scale21 = (numOverflowIntScale < numUnderflowIntScale) ? numOverflowIntScale : numUnderflowIntScale;
  constexpr static scaleType scale22 = (scale21 < denOverflowIntScale) ? scale21 : denOverflowIntScale;
  constexpr static scaleType scale23 = (scale22 < numOverflowFloatScale) ? scale22 : numOverflowFloatScale;
  constexpr static scaleType scale24 = (scale23 < numUnderflowFloatScale) ? scale23 : numUnderflowFloatScale;
  constexpr static scaleType scale2 = (scale24 < denOverflowFloatScale) ? scale24 : denOverflowFloatScale;
  constexpr const static bool needScale2 = numOverflowInt || numUnderflowInt || denOverflowInt || numOverflowFloat || numUnderflowFloat || denOverflowFloat;
  constexpr static numeratorType numerator = needScale2 ? static_cast<numeratorType>(scale2 * static_cast<scaleType>(numerator2sign) * numeratorUnsignedFloat) : (needScale1 ? static_cast<numeratorType>(static_cast<scaleType>(numerator2sign) * numeratorUnsignedFloat) : (numerator2sign * numeratorUnsigned));
  constexpr static denominatorType denominator = needScale2 ? static_cast<denominatorType>(scale2 * numerator2unsignedFloat * static_cast<scaleType>(denominator1contracted)) : (needScale1 ? static_cast<denominatorType>(numerator2unsignedFloat * static_cast<scaleType>(denominator1contracted)) : (numerator2unsigned * denominator1contracted));
  public:
  using type = typename contractType <valueRatio<Type, numerator, denominator> > :: type;
 };

 template <class Type1, class Type2, typename std :: make_signed <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, typename std :: make_signed <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
	 struct dividesType<valueRatio<Type1, Numerator1, Denominator1>, valueRatio<Type2, Numerator2, Denominator2> >
	 : dividesType<
	 valueRatio <typename std :: common_type <Type1, Type2> :: type,
	       static_cast<typename std :: make_signed <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator1),
	       static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator1)>,
	 valueRatio <typename std :: common_type <Type1, Type2> :: type,
	       static_cast<typename std :: make_signed <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator2),
	       static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator2)> >
	 {};

 template <class Type, typename std :: make_signed <Type> :: type ... Numerators, typename std :: make_unsigned <Type> :: type ... Denominators>
	 struct dividesType<valueRatio<Type,Numerators,Denominators>...>
	 : accumulateType<dividesType, valueRatio<Type, Numerators, Denominators>...> {};
}

template <class Type1, class Type2, typename std :: make_signed <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, typename std :: make_signed <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
inline constexpr typename crap :: dividesType <crap :: valueRatio<Type1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Numerator2, Denominator2> > :: type
operator / (crap :: valueRatio<Type1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Numerator2, Denominator2> ) noexcept
{
 return {};
}
#endif

