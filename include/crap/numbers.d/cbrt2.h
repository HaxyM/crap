#ifndef CRAP_NUMBERS_CBRT2
#define CRAP_NUMBERS_CBRT2

namespace crap
{
 template <class> struct cbrt2;

 template <> struct cbrt2<float>
 {
  constexpr const static float value = 1.25992104989487316477f;
 };

 template <> struct cbrt2<double>
 {
  constexpr const static double value = 1.25992104989487316477;
 };

 template <> struct cbrt2<long double>
 {
  constexpr const static double value = 1.25992104989487316477l;
 };
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../ratio.d/cbrt2.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct cbrt2<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename cbrt2 <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

