#ifndef CRAP_CMATH_LEGENDRETYPE
#define CRAP_CMATH_LEGENDRETYPE

namespace crap
{
 template <unsigned int, class> struct legendreType;
}


#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/legendretype.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <unsigned int Order, intmax_t Numerator, intmax_t Denominator>
	 struct legendreType<Order, std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename legendreType <Order, typename typeCast <orig> :: template onto <const1> :: type> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };

 template <unsigned int Order, intmax_t Numerator, intmax_t Denominator>
	 constexpr typename legendreType <Order, std :: ratio<Numerator, Denominator> > :: type
	 legendre(std :: integral_constant<unsigned int, Order>, std :: ratio<Numerator, Denominator>) noexcept;
}

template <unsigned int Order, intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: legendreType <Order, std :: ratio<Numerator, Denominator> > :: type
crap :: legendre(std :: integral_constant<unsigned int, Order>, std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

