#ifndef CRAP_CMATH_ROUNDTYPE
#define CRAP_CMATH_ROUNDTYPE

#include <cstdint>
#include <ratio>

namespace crap
{
 template <class> struct roundType;

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct roundType<std :: ratio<Numerator, Denominator> >
 {
  private:
  using value = std :: ratio<Numerator, Denominator>;
  constexpr const static std :: intmax_t remainder = (value :: num % value :: den);
  constexpr const static bool roundDown = (remainder < 0) ? ((value :: den + remainder) < -remainder) : ((value :: den - remainder) > remainder);
  constexpr const static std :: intmax_t newNum = value :: num / value :: den;
  public:
  using type = std :: ratio<((remainder < 0) ? (roundDown ? (newNum - 1) : newNum) : (roundDown ? newNum : (newNum + 1))), 1>;
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 constexpr typename roundType <std :: ratio<Numerator, Denominator> > :: type
	 round(std :: ratio<Numerator, Denominator>) noexcept;
}

template <std :: intmax_t Numerator, std :: intmax_t Denominator>
inline constexpr typename crap :: roundType <std :: ratio<Numerator, Denominator> > :: type
crap :: round(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif
