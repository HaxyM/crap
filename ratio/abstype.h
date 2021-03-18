#ifndef CRAP_RATIO_ABSTYPE
#define CRAP_RATIO_ABSTYPE

#include "contracttype.h"
#include "valueratio.h"
#include "../numeric/abstype.h"
#include "../numeric/identity.h"
#include "../numeric/zero.h"

#include <limits>
#include <type_traits>

namespace crap
{
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct absType<valueRatio<Type, Numerator, Denominator> >
 {
  private:
  using scaleType = const long double;
  using numeratorType = typename std :: add_const <typename std :: make_signed <Type> :: type> :: type;
  using denominatorType = typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type;
  constexpr static numeratorType numMax = std :: numeric_limits <numeratorType> :: max();
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static numeratorType sign = (Numerator < zero <numeratorType> :: value) ? -(identity <numeratorType> :: value) : identity <numeratorType> :: value;
  constexpr const static bool needScale = (Numerator < zero <numeratorType> :: value) ? (zero <numeratorType> :: value > (numMax + Numerator)) : false;
  constexpr static scaleType scale = needScale ? (static_cast<scaleType>(numMax) / static_cast<scaleType>(sign) / static_cast<scaleType>(Numerator)) : infinity;
  constexpr static scaleType scaledDenominator = needScale ? (scale * static_cast<scaleType>(Denominator)) : static_cast<scaleType>(Denominator);
  constexpr static numeratorType numerator = needScale ? static_cast<numeratorType>(scale * static_cast<scaleType>(sign) * static_cast<scaleType>(Numerator)) : (sign * Numerator);
  constexpr static denominatorType denominator = needScale ? static_cast<denominatorType>((scaledDenominator < 1.0l) ? 1.0l : scaledDenominator) : Denominator;
  public:
  using type = typename contractType <valueRatio<Type, numerator, denominator> > :: type;
 };
}
#endif
