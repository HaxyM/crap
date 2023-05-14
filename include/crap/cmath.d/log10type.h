#ifndef CRAP_CMATH_LOG10TYPE
#define CRAP_CMATH_LOG10TYPE

namespace crap
{
 template <class> struct log10Type;
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/log10type.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <intmax_t Numerator, intmax_t Denominator>
	 struct log10Type<std :: ratio<Numerator, Denominator> >
 {
  private:
  static_assert((Numerator < 0) == (Denominator < 0), "Value must be positive.");
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename log10Type <typename typeCast <orig> :: template onto <const1> :: type> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename log10Type <std :: ratio<Numerator, Denominator> > :: type
	 log10(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: log10Type <std :: ratio<Numerator, Denominator> > :: type
crap :: log10(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

