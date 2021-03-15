#ifndef CRAP_RATIO_NEGATETYPE
#define CRAP_RATIO_NEGATETYPE


#include "contracttype.h"
#include "valueratio.h"
#include "../functional/negatetype.h"
#include "../numeric/identity.h"
#include "../numeric/zero.h"

#include <cmath>
#include <limits>
#include <type_traits>

namespace crap
{
template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct negateType<valueRatio<Type, Numerator, Denominator> >
 {
  private:
  using scaleType = const long double;
  using numeratorType = typename std :: add_const <typename std :: make_signed <Type> :: type> :: type;
  using denominatorType = typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type;
  constexpr static numeratorType numMax = std :: numeric_limits <numeratorType> :: max();
  constexpr static numeratorType numMin = std :: numeric_limits <numeratorType> :: min();
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static const bool numUnderFlow = (Numerator > zero <numeratorType> :: value) && (zero <numeratorType> :: value < (numMin + Numerator));
  constexpr static const bool numOverFlow = (Numerator < zero <numeratorType> :: value) && (zero <numeratorType> :: value > (numMax + Numerator));
  constexpr static scaleType numOverScale = numOverFlow ? std :: abs(-1.0l / (static_cast<scaleType>(Numerator) / static_cast<scaleType>(numMax))) : infinity;
  constexpr static scaleType numUnderScale = numUnderFlow ? std :: abs(-1.0l / (static_cast<scaleType>(Numerator) / static_cast<scaleType>(numMin))) : infinity;
  constexpr static scaleType scale = (numOverScale < numUnderScale) ? numOverScale : numUnderScale;
  constexpr static const bool needScale = (numOverFlow || numUnderFlow);
  constexpr static numeratorType numerator = needScale ? static_cast<numeratorType>(-scale * static_cast<scaleType>(Numerator)) : (-Numerator);
  constexpr static denominatorType denominator = needScale ? static_cast<denominatorType>(scale * static_cast<scaleType>(Denominator)) : Denominator;
  public:
  using type = typename contractType <valueRatio<Type, numerator, (denominator != zero <denominatorType> :: value) ? denominator : identity <denominatorType> :: value> > :: type;
 };
}
#endif

