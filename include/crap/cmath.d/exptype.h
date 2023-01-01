#ifndef CRAP_CMATH_EXPTYPE
#define CRAP_CMATH_EXPTYPE

namespace crap
{
 template <class> struct expType;
}

#include <limits>
#include <ratio>
#include <type_traits>

#include "../functional.d/lesstype.h"
#include "../numbers.d/identity.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/contracttype.h"
#include "../ratio.d/exptype.h"
#include "../ratio.d/identity.h"

namespace crap
{
 template <intmax_t Numerator, intmax_t Denominator>
	 struct expType<std :: ratio<Numerator, Denominator> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const<typename std :: make_unsigned <std :: intmax_t> :: type> :: type;
  using orig = typename contractType <std :: ratio<Numerator, Denominator> > :: type;
  constexpr static const bool origNegative = lessType <orig, typename zero <orig> :: type> :: value;
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType max = static_cast<scaleType>(std :: numeric_limits<std :: intmax_t> :: max());
  constexpr static const bool origNumOverflow =
	  (origNegative && (orig :: num < zero <std :: intmax_t> :: value)) ? (zero <std :: intmax_t> :: value > (max + orig :: num)) : false;
  constexpr static const bool origDenOverflow =
	  (origNegative && (orig :: den < zero <std :: intmax_t> :: value)) ? (zero <std :: intmax_t> :: value > (max + orig :: den)) : false;
  constexpr static scaleType origNumScale = origNumOverflow ? (static_cast<scaleType>(max) / static_cast<scaleType>(orig :: num)) : infinity;
  constexpr static scaleType origDenScale = origDenOverflow ? (static_cast<scaleType>(max) / static_cast<scaleType>(orig :: den)) : infinity;
  constexpr static const bool origNeedScale = origNumOverflow || origDenOverflow;
  constexpr static scaleType origScale = (origNumScale < origDenScale) ? origNumScale : origDenScale;
  constexpr static scaleType sign = origNegative ? -1.0l : 1.0l;
  constexpr static scaleType origNumFloat =
	  origNeedScale ? (origScale * sign * static_cast<scaleType>(orig :: num)) : static_cast<scaleType>(origNegative ? (-orig :: num) : (orig :: num));
  constexpr static scaleType origDenFloat =
	  origNeedScale ? (origScale * sign * static_cast<scaleType>(orig :: den)) : static_cast<scaleType>(origNegative ? (-orig :: den) : (orig :: den));
  constexpr static valueType origScaledNumInRange =
	  (origNumFloat < 0.0l) ? zero <valueType> :: value : (origNumFloat > static_cast<scaleType>(max) ? max : static_cast<valueType>(origNumFloat));
  constexpr static valueType origScaledDenInRange =
	  (origDenFloat < 1.0l) ? identity <valueType> :: value : (origDenFloat > static_cast<scaleType>(max) ? max : static_cast<valueType>(origDenFloat));
  constexpr const static valueType origNum =
	  origNeedScale ? origScaledNumInRange : static_cast<valueType>((orig :: num < zero <std :: intmax_t> :: value) ? (- orig :: num) : (orig :: num));
  constexpr const static valueType origDen =
	  origNeedScale ? origScaledDenInRange : static_cast<valueType>((orig :: den < zero <std :: intmax_t> :: value) ? (- orig :: den) : (orig :: den));
  using value = typename expType <valueRatio<std :: intmax_t, (origNegative ? '-' : '+'), origNum, origDen> > :: type;
  constexpr static scaleType numFloat = static_cast<scaleType>(value :: num);
  constexpr static scaleType denFloat = static_cast<scaleType>(value :: den);
  constexpr static const bool numOverflow = (max <= numFloat);
  constexpr static const bool denOverflow = (max <= denFloat);
  constexpr static const bool needScale = numOverflow || denOverflow;
  constexpr static scaleType numScale = numOverflow ? (max / numFloat) : infinity;
  constexpr static scaleType denScale = denOverflow ? (max / denFloat) : infinity;
  constexpr static scaleType scale = (numScale < denScale) ? numScale : denScale;
  constexpr static std :: intmax_t num =
	  needScale ? static_cast<std :: intmax_t>(scale * numFloat) : static_cast<std :: intmax_t>(value :: num);
  constexpr static std :: intmax_t den =
	  needScale ? static_cast<std :: intmax_t>(scale * denFloat) : static_cast<std :: intmax_t>(value :: den);
  public:
  using type = typename contractType <std :: ratio<num, den> > :: type;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename expType <std :: ratio<Numerator, Denominator> > :: type
	 exp(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: expType <std :: ratio<Numerator, Denominator> > :: type
crap :: exp(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

