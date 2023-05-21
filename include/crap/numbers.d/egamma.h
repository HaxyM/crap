#ifndef CRAP_NUMBERS_EGAMMA
#define CRAP_NUMBERS_EGAMMA

namespace crap
{
 template <class> struct egamma;

 template <> struct egamma<float>
 {
  constexpr const static float value = 0.57721566490153286060f;
 };

 template <> struct egamma<double>
 {
  constexpr const static double value = 0.57721566490153286060;
 };

 template <> struct egamma<long double>
 {
  constexpr const static double value = 0.57721566490153286060l;
 };
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../ratio.d/egamma.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct egamma<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename egamma <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

