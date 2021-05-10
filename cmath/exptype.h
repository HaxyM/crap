#ifndef CRAP_CMATH_EXPTYPE
#define CRAP_CMATH_EXPTYPE

#include "../functional/multipliestype.h"
#include "../functional/plustype.h"
#include "../numeric/innerproducttype.h"
#include "../numeric/iotavalue.h"
#include "../utility/reproducetype.h"

#include <cstddef>
#include <ratio>
#include <type_traits>

namespace crap
{
 template <class, std :: size_t Steps = 10u> struct expType;

 template <intmax_t Numerator, intmax_t Denominator, std :: size_t Steps>
	 struct expType<std :: ratio<Numerator, Denominator>, Steps>
 {
  private:
  template <std :: size_t N> using constant = std :: ratio<1, N>;
  template <std :: size_t N> using reproduce = reproduceType<N, std :: ratio<Numerator, Denominator> >;
  template <std :: size_t ... N> using constants = innerProductType<multipliesType, multipliesType, constant<N>...>;
  template <std :: size_t N> using at = typename reproduce <N> :: template
	  type <iotaValue <N, std :: size_t, 1u> :: template type <constants> :: template with> :: type;
  template <std :: size_t ... N> using sum = typename plusType <std :: ratio<1, 1>, at<N>...> :: type;
  public:
  using type = typename iotaValue <Steps, std :: size_t, 1u> :: template type<sum>;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename expType <std :: ratio<Numerator, Denominator> > :: type
	 exp(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: expType <std :: ratio<Numerator, Denominator> > :: type
crap :: exp(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

