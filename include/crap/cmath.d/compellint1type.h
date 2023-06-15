#ifndef CRAP_CMATH_COMPELLINT1TYPE
#define CRAP_CMATH_COMPELLINT1TYPE

namespace crap
{
 template <class> struct compEllint1Type;
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/compellint1type.h"
#include "../ratio.d/identity.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <intmax_t Numerator, intmax_t Denominator>
	 struct compEllint1Type<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename compEllint1Type <typename typeCast <orig> :: template onto <const1> :: type> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename compEllint1Type <std :: ratio<Numerator, Denominator> > :: type
	 comp_ellint_1(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: compEllint1Type <std :: ratio<Numerator, Denominator> > :: type
crap :: comp_ellint_1(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

