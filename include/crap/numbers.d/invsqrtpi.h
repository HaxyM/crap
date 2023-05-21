#ifndef CRAP_NUMBERS_INVSQRTPI
#define CRAP_NUMBERS_INVSQRTPI

namespace crap
{
 template <class> struct invSqrtPi;

 template <> struct invSqrtPi<float>
 {
  constexpr const static float value = 0.56418958354775628694f;
 };

 template <> struct invSqrtPi<double>
 {
  constexpr const static double value = 0.56418958354775628694;
 };

 template <> struct invSqrtPi<long double>
 {
  constexpr const static double value = 0.56418958354775628694l;
 };
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/invsqrtpi.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct invSqrtPi<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename invSqrtPi <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

