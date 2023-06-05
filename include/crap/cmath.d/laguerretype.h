#ifndef CRAP_CMATH_LAGUERRETYPE
#define CRAP_CMATH_LAGUERRETYPE

namespace crap
{
 template <unsigned int, class> struct laguerreType;
}


#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/laguerretype.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <unsigned int Order, intmax_t Numerator, intmax_t Denominator>
	 struct laguerreType<Order, std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename laguerreType <Order, typename typeCast <orig> :: template onto <const1> :: type> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };

 template <unsigned int Order, intmax_t Numerator, intmax_t Denominator>
	 constexpr typename laguerreType <Order, std :: ratio<Numerator, Denominator> > :: type
	 laguerre(std :: integral_constant<unsigned int, Order>, std :: ratio<Numerator, Denominator>) noexcept;
}

template <unsigned int Order, intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: laguerreType <Order, std :: ratio<Numerator, Denominator> > :: type
crap :: laguerre(std :: integral_constant<unsigned int, Order>, std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

