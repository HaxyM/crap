#ifndef CRAP_NUMBERS_SQRT3
#define CRAP_NUMBERS_SQRT3

namespace crap
{
 template <class> struct sqrt3;

 template <> struct sqrt3<float>
 {
  constexpr const static float value = 1.73205080756887729353f;
 };

 template <> struct sqrt3<double>
 {
  constexpr const static double value = 1.73205080756887729353;
 };

 template <> struct sqrt3<long double>
 {
  constexpr const static double value = 1.73205080756887729353l;
 };
}

#include <limits>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../numeric.d/contracttype.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/sqrt3.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct sqrt3<std :: ratio<Numerator, Denominator> >
 {
  private:
  using scaleType = const long double;
  using valueType = typename std :: add_const<typename std :: make_unsigned <std :: intmax_t> :: type> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: intmax_t, '+', int_1, int_1> > :: type;
  using value = typename sqrt3 <ratio_1> :: type;
  constexpr static scaleType infinity = std :: numeric_limits <scaleType> :: infinity();
  constexpr static scaleType max = static_cast<scaleType>(std :: numeric_limits<std :: intmax_t> :: max());
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
}
#endif

