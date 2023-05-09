#ifndef CRAP_NUMBERS_PI
#define CRAP_NUMBERS_PI

namespace crap
{
 template <class> struct pi;

 template <> struct pi<float>
 {
  constexpr const static float value = 3.14159265358979323846f;
 };

 template <> struct pi<double>
 {
  constexpr const static double value = 3.14159265358979323846;
 };

 template <> struct pi<long double>
 {
  constexpr const static double value = 3.14159265358979323846l;
 };
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/pi.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct pi<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename pi <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

