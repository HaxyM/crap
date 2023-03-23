#ifndef CRAP_CMATH_HYPOTTYPE
#define CRAP_CMATH_HYPOTTYPE

namespace crap
{
 template <class...> struct hypotType;
}

#include <limits>
#include <ratio>
#include <type_traits>

#include "../functional.d/lesstype.h"
#include "../numbers.d/identity.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/contracttype.h"
#include "../ratio.d/hypottype.h"
#include "../ratio.d/identity.h"

namespace crap
{
 template <intmax_t ... Numerators, intmax_t ... Denominators>
	 struct hypotType<std :: ratio<Numerators, Denominators>...>
 {
  private:
  template <class> struct ratioCast;
  template <std :: intmax_t Num, std :: intmax_t Den> struct ratioCast<std :: ratio<Num, Den> >;
  template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Num, typename std :: make_unsigned <Type> :: type Den>
	  struct ratioCast<valueRatio<Type, Sign, Num, Den> >;
  using value = typename hypotType <typename ratioCast<std :: ratio<Numerators, Denominators> > :: type...> :: type;
  public:
  using type = typename ratioCast <value> :: type;
 };

 template <intmax_t ... Numerators, intmax_t ... Denominators>
	 template <std :: intmax_t Num, std :: intmax_t Den>
 struct hypotType <std :: ratio<Numerators, Denominators>...> :: template
	 ratioCast<std :: ratio<Num, Den> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const<typename std :: make_unsigned <std :: intmax_t> :: type> :: type;
  using value = typename contractType <std :: ratio<Num, Den> > :: type;
  constexpr static const bool negative = lessType <value, typename zero <value> :: type> :: value;
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType max = static_cast<scaleType>(std :: numeric_limits<std :: intmax_t> :: max());
  constexpr static const bool numOverflow =
	  (negative && (value :: num < zero <std :: intmax_t> :: value)) ?
	  (zero <std :: intmax_t> :: value > (max + value :: num)) : false;
  constexpr static const bool denOverflow =
	  (negative && (value :: den < zero <std :: intmax_t> :: value)) ?
	  (zero <std :: intmax_t> :: value > (max + value :: den)) : false;
  constexpr static scaleType numScale =
	  numOverflow ? (static_cast<scaleType>(max) / static_cast<scaleType>(value :: num)) : infinity;
  constexpr static scaleType denScale =
	  denOverflow ? (static_cast<scaleType>(max) / static_cast<scaleType>(value :: den)) : infinity;
  constexpr static const bool needScale = numOverflow || denOverflow;
  constexpr static scaleType scale = (numScale < denScale) ? numScale : denScale;
  constexpr static scaleType sign = negative ? -1.0l : 1.0l;
  constexpr static scaleType numFloat =
	  needScale ?
	  (scale * sign * static_cast<scaleType>(value :: num)) :
	  static_cast<scaleType>(negative ? (-value :: num) : (value :: num));
  constexpr static scaleType denFloat =
	  needScale ?
	  (scale * sign * static_cast<scaleType>(value :: den)) :
	  static_cast<scaleType>(negative ? (-value :: den) : (value :: den));
  constexpr static valueType scaledNumInRange =
	  (numFloat < 0.0l) ?
	  zero <valueType> :: value :
	  (numFloat > static_cast<scaleType>(max) ? max : static_cast<valueType>(numFloat));
  constexpr static valueType scaledDenInRange =
	  (denFloat < 1.0l) ?
	  identity <valueType> :: value :
	  (denFloat > static_cast<scaleType>(max) ? max : static_cast<valueType>(denFloat));
  constexpr const static valueType num =
	  needScale ?
	  scaledNumInRange :
	  static_cast<valueType>((value :: num < zero <std :: intmax_t> :: value) ? (-value :: num) : (value :: num));
  constexpr const static valueType den =
	  needScale ?
	  scaledDenInRange :
	  static_cast<valueType>((value :: den < zero <std :: intmax_t> :: value) ? (-value :: den) : (value :: den));
  public:
  using type = typename contractType <valueRatio<std :: intmax_t, (negative ? '-' : '+'), num, den> > :: type;
 };

 template <intmax_t ... Numerators, intmax_t ... Denominators>
	 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Num, typename std :: make_unsigned <Type> :: type Den>
 struct hypotType <std :: ratio<Numerators, Denominators>...> :: template
	 ratioCast<valueRatio<Type, Sign, Num, Den> >
 {
  private:
  using scaleType = const long double;
  using value = typename contractType <valueRatio<Type, Sign, Num, Den> > :: type;
  constexpr static const bool negative = (value :: sign == '-');
  constexpr static const std :: intmax_t max = std :: numeric_limits<std :: intmax_t> :: max();
  constexpr static const std :: intmax_t min = std :: numeric_limits<std :: intmax_t> :: min();
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType signFloat = negative ? -1.0l : 1.0l;
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
	  (scaledNum < static_cast<scaleType>(min)) ?
	  min : ((scaledNum > static_cast<scaleType>(max)) ? max : static_cast<std :: intmax_t>(scaledNum));
  constexpr static std :: intmax_t scaledDenInRange =
	  (scaledDen < 1.0l) ?
	  identity <std :: intmax_t> :: value :
	  ((scaledDen > static_cast<scaleType>(max)) ? max : static_cast<std :: intmax_t>(scaledDen));
  constexpr static std :: intmax_t num =
	  needScale ?
	  static_cast<std :: intmax_t>(scaledNumInRange) :
	  (negative ? -static_cast<std :: intmax_t>(value :: num) : static_cast<std :: intmax_t>(value :: num));
  constexpr static std :: intmax_t den =
	  needScale ? static_cast<std :: intmax_t>(scaledDenInRange) : static_cast<std :: intmax_t>(value :: den);
  public:
  using type = typename contractType <std :: ratio<num, den> > :: type;
 };

 template <intmax_t ... Numerators, intmax_t ... Denominators>
	 constexpr typename hypotType <std :: ratio<Numerators, Denominators>...> :: type
	 hypot(std :: ratio<Numerators, Denominators>...) noexcept;
}

template <intmax_t ... Numerators, intmax_t ... Denominators>
inline constexpr typename crap :: hypotType <std :: ratio<Numerators, Denominators>...> :: type
crap :: hypot(std :: ratio<Numerators, Denominators>...) noexcept
{
 return {};
}
#endif

