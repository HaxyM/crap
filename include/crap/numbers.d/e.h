#ifndef CRAP_NUMBERS_E
#define CRAP_NUMBERS_E

namespace crap
{
 template <class> struct e;

 template <> struct e<float>
 {
  constexpr const static float value = 2.71828182845904523536f;
 };

 template <> struct e<double>
 {
  constexpr const static double value = 2.71828182845904523536;
 };

 template <> struct e<long double>
 {
  constexpr const static double value = 2.71828182845904523536l;
 };
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../ratio.d/e.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct e<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename e <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

