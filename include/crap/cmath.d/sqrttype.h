#ifndef CRAP_CMATH_SQRTTYPE
#define CRAP_CMATH_SQRTTYPE

namespace crap
{
 template <class> struct sqrtType;
}

#include <limits>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../numeric.d/contracttype.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/sqrttype.h"

namespace crap
{
 template <intmax_t Numerator, intmax_t Denominator>
	 struct sqrtType<std :: ratio<Numerator, Denominator> >
 {
  private:
  static_assert((Numerator < 0) == (Denominator < 0), "Value must be positive.");
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename sqrtType <typename typeCast <orig> :: template onto <const1> :: type> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename sqrtType <std :: ratio<Numerator, Denominator> > :: type
	 sqrt(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: sqrtType <std :: ratio<Numerator, Denominator> > :: type
crap :: sqrt(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

