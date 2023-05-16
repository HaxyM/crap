#ifndef CRAP_CMATH_HYPOTTYPE
#define CRAP_CMATH_HYPOTTYPE

namespace crap
{
 template <class...> struct hypotType;
}

#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/hypottype.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <intmax_t ... Numerators, intmax_t ... Denominators>
	 struct hypotType<std :: ratio<Numerators, Denominators>...>
 {
  private:
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	  using input = typename typeCast <std :: ratio<Numerator, Denominator> > :: template
	  onto <const1> :: type;
  using value = typename hypotType <input<Numerators, Denominators>...> :: type;
  using output = std :: ratio<UINTMAX_C(0), UINTMAX_C(1)>;
  public:
  using type = typename typeCast <value> :: template onto <output> :: type;
 };

 template <intmax_t ... Numerators, intmax_t ... Denominators>
	 constexpr typename hypotType <std :: ratio<Numerators, Denominators>...> :: type
	 hypot(std :: ratio<Numerators, Denominators>...) noexcept;
}

template <intmax_t ... Numerators, intmax_t ... Denominators>
inline constexpr typename crap :: hypotType <std :: ratio<Numerators, Denominators>...> :: type
crap :: hypot(std :: ratio<Numerators, Denominators>...) noexcept
{
 return {};
}
#endif

