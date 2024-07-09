#ifndef CRAP_CMATH_ASSOCLEGENDRETYPE
#define CRAP_CMATH_ASSOCLEGENDRETYPE

namespace crap
{
 template <unsigned int, unsigned int, class> struct assocLegendreType;
}


#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/assoclegendretype.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <unsigned int Degree, unsigned int Order, intmax_t Numerator, intmax_t Denominator>
	 struct assocLegendreType<Degree, Order, std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename assocLegendreType <Degree, Order, typename typeCast <orig> :: template onto <const1> :: type> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };

 template <unsigned int Degree, unsigned int Order, intmax_t Numerator, intmax_t Denominator>
	 constexpr typename assocLegendreType <Degree, Order, std :: ratio<Numerator, Denominator> > :: type
	 assoc_legendre(std :: integral_constant<unsigned int, Degree>, std :: integral_constant<unsigned int, Order>, std :: ratio<Numerator, Denominator>) noexcept;
}

template <unsigned int Degree, unsigned int Order, intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: assocLegendreType <Degree, Order, std :: ratio<Numerator, Denominator> > :: type
crap :: assoc_legendre(std :: integral_constant<unsigned int, Degree>, std :: integral_constant<unsigned int, Order>, std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

