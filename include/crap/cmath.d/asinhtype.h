#ifndef CRAP_CMATH_ASINHTYPE
#define CRAP_CMATH_ASINHTYPE

namespace crap
{
 template <class> struct asinhType;
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/asinhtype.h"
#include "../ratio.d/identity.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <intmax_t Numerator, intmax_t Denominator>
	 struct asinhType<std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename asinhType <typename typeCast <orig> :: template onto <const1> :: type> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename asinhType <std :: ratio<Numerator, Denominator> > :: type
	 asinh(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: asinhType <std :: ratio<Numerator, Denominator> > :: type
crap :: asinh(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

