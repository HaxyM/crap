#ifndef CRAP_CMATH_COPYSIGNTYPE
#define CRAP_CMATH_COPYSIGNTYPE

#include <ratio>
#include <limits>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/contracttype.h"

namespace crap
{
 template <class, class> struct copysignType;

 template <intmax_t magnitudeNumerator, intmax_t magnitudeDenominator, intmax_t signNumerator, intmax_t signDenominator>
	 struct copysignType<std :: ratio<magnitudeNumerator, magnitudeDenominator>, std :: ratio<signNumerator, signDenominator> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const <intmax_t> :: type;
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static valueType max = std :: numeric_limits <valueType> :: max();
  constexpr static valueType min = std :: numeric_limits <valueType> :: min();
  using magnitude = typename contractType <std :: ratio<magnitudeNumerator, magnitudeDenominator> > :: type;
  using sign = typename contractType <std :: ratio<signNumerator, signDenominator> > :: type;
  constexpr static const bool isMagnitudeNegative =
	  ((magnitude :: num < zero <valueType> :: value) != (magnitude :: den < zero <valueType> :: value));
  constexpr static const bool isSignNegative =
	  ((sign :: num < zero <valueType> :: value) != (sign :: den < zero <valueType> :: value));
  constexpr static const bool isSignChanged = (isMagnitudeNegative != isSignNegative);
  constexpr static const bool overflow =
	  (isMagnitudeNegative && isSignChanged) ? (zero <valueType> :: value > (max + magnitude :: num)) : false;
  constexpr static const bool underflow =
	  (!isMagnitudeNegative && isSignChanged) ? (zero <valueType> :: value < (min + magnitude :: num)) : false;
  constexpr static const bool needScale = (overflow || underflow);
  constexpr static scaleType overflowScale =
	  overflow ? (-static_cast<scaleType>(magnitude :: num) / static_cast<scaleType>(max)) : infinity;
  constexpr static scaleType underflowScale =
	  underflow ? (-static_cast<scaleType>(magnitude :: num) / static_cast<scaleType>(min)) : infinity;
  constexpr static scaleType scale = (overflowScale < underflowScale) ? overflowScale : underflowScale;
  constexpr static scaleType factor = isSignChanged ? -1.0l : 1.0l; 
  constexpr static scaleType scaledNumerator =
	  needScale ?
	  (scale * factor * static_cast<scaleType>(magnitude :: num)) :
	  (factor * static_cast<scaleType>(magnitude :: num));
  constexpr static scaleType scaledDenominator =
	  needScale ?
	  (scale * static_cast<scaleType>(magnitude :: den)) :
	  (static_cast<scaleType>(magnitude :: den));
  constexpr static valueType scaledNumeratorInRange =
	  (scaledNumerator < static_cast<scaleType>(min)) ?
	  min :
	  ((scaledNumerator > static_cast<scaleType>(max)) ? max : static_cast<valueType>(scaledNumerator));
  constexpr static valueType scaledDenominatorInRange =
	  (scaledDenominator < 1.0l) ?
	  identity <valueType> :: value :
	  ((scaledDenominator > static_cast<scaleType>(max)) ? max : static_cast<valueType>(scaledDenominator));
  constexpr static valueType numerator =
	  needScale ? scaledNumeratorInRange : (isSignChanged ? (-(magnitude :: num)) : (magnitude :: num));
  constexpr static valueType denominator = needScale ? scaledDenominatorInRange : magnitude :: den;
  public:
  using type = typename contractType <std :: ratio<numerator, denominator> > :: type;
 };
}
#endif

