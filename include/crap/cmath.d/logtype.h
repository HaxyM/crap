#ifndef CRAP_CMATH_LOGTYPE
#define CRAP_CMATH_LOGTYPE

#include "../functional.d/dividestype.h"
#include "../functional.d/minustype.h"
#include "../functional.d/multipliestype.h"
#include "../functional.d/plustype.h"
#include "../numbers.d/identity.h"
#include "../numeric.d/innerproducttype.h"
#include "../numeric.d/iotavalue.h"
#include "../utility.d/reproducetype.h"

#include <cstddef>
#include <ratio>
#include <type_traits>

namespace crap
{
 template <class> struct logType;
}

#include <limits>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../numeric.d/contracttype.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/logtype.h"

namespace crap
{
 template <intmax_t Numerator, intmax_t Denominator>
	 struct logType<std :: ratio<Numerator, Denominator> >
 {
  private:
  static_assert((Numerator < 0) == (Denominator < 0), "Value must be positive.");
  using scaleType = const long double;
  using valueType = typename std :: add_const<typename std :: make_unsigned <std :: intmax_t> :: type> :: type;
  using orig = typename contractType <std :: ratio<Numerator, Denominator> > :: type;
  constexpr const static valueType origNum = static_cast<valueType>(orig :: num);
  constexpr const static valueType origDen = static_cast<valueType>(orig :: den);
  using value = typename logType <valueRatio<std :: intmax_t, '+', origNum, origDen> > :: type;
  constexpr static const bool valueNegative = (value :: sign == '-');
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static const std :: intmax_t max = std :: numeric_limits<std :: intmax_t> :: max();
  constexpr static const std :: intmax_t min = std :: numeric_limits<std :: intmax_t> :: min();
  constexpr static scaleType signFloat = valueNegative ? -1.0l : 1.0l;
  constexpr static scaleType numFloat = signFloat * static_cast<scaleType>(value :: num);
  constexpr static scaleType denFloat = static_cast<scaleType>(value :: den);
  constexpr static const bool numOverflow = (static_cast<scaleType>(max) <= numFloat);
  constexpr static const bool denOverflow = (static_cast<scaleType>(max) <= denFloat);
  constexpr static const bool numUnderflow = (static_cast<scaleType>(min) >= numFloat);
  constexpr static const bool denUnderflow = (static_cast<scaleType>(min) >= denFloat);
  constexpr static const bool needScale = numOverflow || denOverflow || numUnderflow || denUnderflow;
  constexpr static scaleType numOverScale = numOverflow ? (static_cast<scaleType>(max) / numFloat) : infinity;
  constexpr static scaleType denOverScale = denOverflow ? (static_cast<scaleType>(max) / denFloat) : infinity;
  constexpr static scaleType numUnderScale = numUnderflow ? (static_cast<scaleType>(min) / numFloat) : infinity;
  constexpr static scaleType denUnderScale = denUnderflow ? (static_cast<scaleType>(min) / denFloat) : infinity;
  constexpr static scaleType overScale = (numOverScale < denOverScale) ? numOverScale : denOverScale;
  constexpr static scaleType underScale = (numUnderScale < denUnderScale) ? numUnderScale : denUnderScale;
  constexpr static scaleType scale = (overScale < underScale) ? overScale : underScale;
  constexpr static scaleType scaledNum = needScale ? (scale * numFloat) : numFloat;
  constexpr static scaleType scaledDen = needScale ? (scale * denFloat) : denFloat;
  constexpr static std :: intmax_t scaledNumInRange =
	  (scaledNum < static_cast<scaleType>(min)) ? min : ((scaledNum > static_cast<scaleType>(max)) ? max : static_cast<std :: intmax_t>(scaledNum));
  constexpr static std :: intmax_t scaledDenInRange =
	  (scaledDen < 1.0l) ? identity <std :: intmax_t> :: value : ((scaledDen > static_cast<scaleType>(max)) ? max : static_cast<std :: intmax_t>(scaledDen));
  constexpr static std :: intmax_t num =
	  needScale ? static_cast<std :: intmax_t>(scaledNumInRange) : (valueNegative ? -static_cast<std :: intmax_t>(value :: num) : static_cast<std :: intmax_t>(value :: num));
  constexpr static std :: intmax_t den =
	  needScale ? static_cast<std :: intmax_t>(scaledDenInRange) : static_cast<std :: intmax_t>(value :: den);
  public:
  using type = typename contractType <std :: ratio<num, den> > :: type;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename logType <std :: ratio<Numerator, Denominator> > :: type
	 log(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: logType <std :: ratio<Numerator, Denominator> > :: type
crap :: log(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

