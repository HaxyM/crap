#ifndef CRAP_CMATH_LOG10TYPE
#define CRAP_CMATH_LOG10TYPE

#include "logtype.h"
#include "../functional.d/dividestype.h"

#include <cstddef>
#include <ratio>
#include <type_traits>

namespace crap
{
 template <class, std :: size_t Steps = 10u> struct log10Type;

 template <intmax_t Numerator, intmax_t Denominator, std :: size_t Steps>
	 struct log10Type<std :: ratio<Numerator, Denominator>, Steps>
 {
  private:
  using base = typename logType <std :: ratio<10, 1>, Steps> :: type;
  using ln = typename logType <std :: ratio<Numerator, Denominator>, Steps> :: type;
  public:
  using type = typename dividesType <ln, base> :: type;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename log10Type <std :: ratio<Numerator, Denominator> > :: type
	 log10(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: log10Type <std :: ratio<Numerator, Denominator> > :: type
crap :: log10(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

