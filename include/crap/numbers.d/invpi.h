#ifndef CRAP_NUMBERS_INVPI
#define CRAP_NUMBERS_INVPI

namespace crap
{
 template <class> struct invPi;

 template <> struct invPi<float>
 {
  constexpr const static float value = 0.31830988618379067153f;
 };

 template <> struct invPi<double>
 {
  constexpr const static double value = 0.31830988618379067153;
 };

 template <> struct invPi<long double>
 {
  constexpr const static double value = 0.31830988618379067153l;
 };
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/invpi.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct invPi<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename invPi <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

