#ifndef CRAP_CMATH_HERMITETYPE
#define CRAP_CMATH_HERMITETYPE

namespace crap
{
 template <unsigned int, class> struct hermiteType;
}


#include <cstdint>
#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../ratio.d/identity.h"
#include "../ratio.d/hermitetype.h"
#include "../utility.d/typecast.h"

namespace crap
{
 template <unsigned int Order, intmax_t Numerator, intmax_t Denominator>
	 struct hermiteType<Order, std :: ratio<Numerator, Denominator> >
 {
  private:
  using orig = std :: ratio<Numerator, Denominator>;
  using valueType = typename std :: add_const<std :: uintmax_t> :: type;
  constexpr static valueType int_1 = identity <valueType> :: value;
  using const1 = typename identity <valueRatio<std :: uintmax_t, '+', int_1, int_1> > :: type;
  using value = typename hermiteType <Order, typename typeCast <orig> :: template onto <const1> :: type> :: type;
  public:
  using type = typename typeCast <value> :: template onto <orig> :: type;
 };

 template <unsigned int Order, intmax_t Numerator, intmax_t Denominator>
	 constexpr typename hermiteType <Order, std :: ratio<Numerator, Denominator> > :: type
	 hermite(std :: integral_constant<unsigned int, Order>, std :: ratio<Numerator, Denominator>) noexcept;
}

template <unsigned int Order, intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: hermiteType <Order, std :: ratio<Numerator, Denominator> > :: type
crap :: hermite(std :: integral_constant<unsigned int, Order>, std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

