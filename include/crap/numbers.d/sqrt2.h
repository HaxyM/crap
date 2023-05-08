#ifndef CRAP_NUMBERS_SQRT2
#define CRAP_NUMBERS_SQRT2

namespace crap
{
 template <class> struct sqrt2;

 template <> struct sqrt2<float>
 {
  constexpr const static float value = 1.4142135623730950488f;
 };

 template <> struct sqrt2<double>
 {
  constexpr const static double value = 1.4142135623730950488;
 };

 template <> struct sqrt2<long double>
 {
  constexpr const static double value = 1.4142135623730950488l;
 };
}

#include <limits>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../numeric.d/contracttype.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/sqrt2.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct sqrt2<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename sqrt2 <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

