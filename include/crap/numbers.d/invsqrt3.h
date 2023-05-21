#ifndef CRAP_NUMBERS_INVSQRT3
#define CRAP_NUMBERS_INVSQRT3

namespace crap
{
 template <class> struct invSqrt3;

 template <> struct invSqrt3<float>
 {
  constexpr const static float value = 0.57735026918962576451f;
 };

 template <> struct invSqrt3<double>
 {
  constexpr const static double value = 0.57735026918962576451;
 };

 template <> struct invSqrt3<long double>
 {
  constexpr const static double value = 0.57735026918962576451l;
 };
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/invsqrt3.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct invSqrt3<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename invSqrt3 <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

