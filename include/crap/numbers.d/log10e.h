#ifndef CRAP_NUMBERS_LOG10E
#define CRAP_NUMBERS_LOG10E

namespace crap
{
 template <class> struct log10e;

 template <> struct log10e<float>
 {
  constexpr const static float value = 0.43429448190325182765f;
 };

 template <> struct log10e<double>
 {
  constexpr const static double value = 0.43429448190325182765;
 };

 template <> struct log10e<long double>
 {
  constexpr const static double value = 0.43429448190325182765l;
 };
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/log10e.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct log10e<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename log10e <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

