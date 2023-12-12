#ifndef CRAP_CMATH_ASSOCLAGUERRETYPE
#define CRAP_CMATH_ASSOCLAGUERRETYPE

namespace crap
{
 template <unsigned int, unsigned int, class> struct assocLaguerreType;
}


#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/assoclaguerretype.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <unsigned int Order, unsigned int Alpha, intmax_t Numerator, intmax_t Denominator>
	 struct assocLaguerreType<Order, Alpha, std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename assocLaguerreType <Order, Alpha, typename typeCast <orig> :: template onto <const1> :: type> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };

 template <unsigned int Order, unsigned int Alpha, intmax_t Numerator, intmax_t Denominator>
	 constexpr typename assocLaguerreType <Order, Alpha, std :: ratio<Numerator, Denominator> > :: type
	 assoc_laguerre(std :: integral_constant<unsigned int, Order>, std :: integral_constant<unsigned int, Alpha>, std :: ratio<Numerator, Denominator>) noexcept;
}

template <unsigned int Order, unsigned int Alpha, intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: assocLaguerreType <Order, Alpha, std :: ratio<Numerator, Denominator> > :: type
crap :: assoc_laguerre(std :: integral_constant<unsigned int, Order>, std :: integral_constant<unsigned int, Alpha>, std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

