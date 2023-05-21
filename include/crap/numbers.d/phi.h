#ifndef CRAP_NUMBERS_PHI
#define CRAP_NUMBERS_PHI

namespace crap
{
 template <class> struct phi;

 template <> struct phi<float>
 {
  constexpr const static float value = 1.6180339887498948482f;
 };

 template <> struct phi<double>
 {
  constexpr const static double value = 1.6180339887498948482;
 };

 template <> struct phi<long double>
 {
  constexpr const static double value = 1.6180339887498948482l;
 };
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/phi.h"
#include "../ratio.d/valueratio.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct phi<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr const static valueType int_1 = identity <valueType> :: value;
  using ratio_1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename phi <ratio_1> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };
}
#endif

