#ifndef CRAP_NUMBERS_LN10
#define CRAP_NUMBERS_LN10

namespace crap
{
 template <class> struct ln10;

 template <> struct ln10<float>
 {
  constexpr const static float value = 2.30258509299404568402f;
 };

 template <> struct ln10<double>
 {
  constexpr const static double value = 2.30258509299404568402;
 };

 template <> struct ln10<long double>
 {
  constexpr const static double value = 2.30258509299404568402l;
 };
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/ln10.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct ln10<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename ln10 <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

