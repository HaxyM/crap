#ifndef CRAP_NUMBERS_LN2
#define CRAP_NUMBERS_LN2

namespace crap
{
 template <class> struct ln2;

 template <> struct ln2<float>
 {
  constexpr const static float value = 0.69314718055994530942f;
 };

 template <> struct ln2<double>
 {
  constexpr const static double value = 0.69314718055994530942;
 };

 template <> struct ln2<long double>
 {
  constexpr const static double value = 0.69314718055994530942l;
 };
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/ln2.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct ln2<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename ln2 <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

