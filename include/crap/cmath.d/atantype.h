#ifndef CRAP_CMATH_ATANTYPE
#define CRAP_CMATH_ATANTYPE

namespace crap
{
 template <class> struct atanType;
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/atantype.h"
#include "../ratio.d/identity.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <intmax_t Numerator, intmax_t Denominator>
	 struct atanType<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename atanType <typename typeCast <orig> :: template onto <const1> :: type> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename atanType <std :: ratio<Numerator, Denominator> > :: type
	 atan(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: atanType <std :: ratio<Numerator, Denominator> > :: type
crap :: atan(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

