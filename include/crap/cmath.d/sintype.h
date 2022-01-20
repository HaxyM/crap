#ifndef CRAP_CMATH_SINTYPE
#define CRAP_CMATH_SINTYPE

#include "../functional.d/multipliestype.h"
#include "../functional.d/negatetype.h"
#include "../functional.d/plustype.h"
#include "../numeric.d/iotavalue.h"

#include <cstddef>
#include <ratio>

namespace crap
{
 template <class, std :: size_t Steps = 10u> struct sinType;

 template <intmax_t Numerator, intmax_t Denominator, std :: size_t Steps>
	 struct sinType<std :: ratio<Numerator, Denominator>, Steps>
 {
  private:
  using x = std :: ratio<Numerator, Denominator>;
  template <std :: intmax_t N> using constant1 = std :: ratio<1, 2 * N + 1>;
  template <std :: intmax_t N> using constant2 = std :: ratio<1, 2 * N + 2>;
  template <std :: intmax_t N> using prodTerm1 = typename multipliesType <x, constant1<N> > :: type;
  template <std :: intmax_t N> using prodTerm2 = typename multipliesType <x, constant2<N> > :: type;
  template <std :: intmax_t N>
	  using prodTerm = typename negateType <typename multipliesType <prodTerm1<N>, prodTerm2<N> > :: type> :: type;
  template <std :: intmax_t ... N>
	  using product = typename multipliesType <prodTerm<N>..., prodTerm1<sizeof...(N)> > :: type;
  template <std :: size_t N> using sumTerm = typename iotaValue <N, std :: intmax_t, 0> :: template type<product>;
  template <std :: size_t ... N> using sum = typename plusType <x, sumTerm<N>...> :: type;
  public:
  using type = typename iotaValue <Steps, std :: size_t, 1> :: template type<sum>;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename sinType <std :: ratio<Numerator, Denominator> > :: type
	 sin(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: sinType <std :: ratio<Numerator, Denominator> > :: type
crap :: sin(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

