#ifndef CRAP_NUMBERS_LOG2E
#define CRAP_NUMBERS_LOG2E

namespace crap
{
 template <class> struct log2e;

 template <> struct log2e<float>
 {
  constexpr const static float value = 1.44269504088896340735f;
 };

 template <> struct log2e<double>
 {
  constexpr const static double value = 1.44269504088896340735;
 };

 template <> struct log2e<long double>
 {
  constexpr const static double value = 1.44269504088896340735l;
 };
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/log2e.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct log2e<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename log2e <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

