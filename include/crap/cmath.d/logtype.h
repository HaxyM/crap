#ifndef CRAP_CMATH_LOGTYPE
#define CRAP_CMATH_LOGTYPE

#include "../functional.d/dividestype.h"
#include "../functional.d/minustype.h"
#include "../functional.d/multipliestype.h"
#include "../functional.d/plustype.h"
#include "../numbers.d/identity.h"
#include "../numeric.d/innerproducttype.h"
#include "../numeric.d/iotavalue.h"
#include "../utility.d/reproducetype.h"

#include <cstddef>
#include <ratio>
#include <type_traits>

namespace crap
{
 template <class, std :: size_t Steps = 10u> struct logType;

 template <intmax_t Numerator, intmax_t Denominator, std :: size_t Steps>
	 struct logType<std :: ratio<Numerator, Denominator>, Steps>
 {
  private:
  using z = std :: ratio<Numerator, Denominator>;
  using argument = typename dividesType <typename minusType <z, typename identity <z> :: type> :: type, typename plusType <z, typename identity <z> :: type> :: type> :: type;
  template <std :: size_t N> using constant = std :: ratio<1, N>;
  template <std :: size_t N>
	  using power = typename reproduceType<N, argument> :: template type<multipliesType> :: type;
  template <std :: size_t ... N> using constants = innerProductType<plusType, multipliesType, constant<N>...>;
  template <std :: size_t ... N>
	  using odds = typename constants <(2u * N + 1u)...> :: template with <power<2u * N + 1u>...> :: type;
  using half = plusType<argument, typename iotaValue <Steps, std :: size_t, 1u> :: template type<odds> >;
  public:
  using type = typename plusType <typename half :: type, typename half :: type> :: type;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename logType <std :: ratio<Numerator, Denominator> > :: type
	 log(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: logType <std :: ratio<Numerator, Denominator> > :: type
crap :: log(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

