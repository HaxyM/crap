#ifndef CRAP_CMATH_CEILTYPE
#define CRAP_CMATH_CEILTYPE

#include <cstdint>
#include <ratio>

namespace crap
{
 template <class> struct ceilType;

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct ceilType<std :: ratio<Numerator, Denominator> >
 {
  private:
  using value = std :: ratio<Numerator, Denominator>;
  constexpr const static bool whole = ((value :: num % value :: den) == 0);
  constexpr const static bool negative = ((value :: num < 0) != ( value :: den < 0));
  constexpr const static std :: intmax_t newNum = value :: num / value :: den;
  public:
  using type = std :: ratio<((whole || negative) ? newNum : (newNum + 1)), 1>;
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 constexpr typename ceilType <std :: ratio<Numerator, Denominator> > :: type
	 ceil(std :: ratio<Numerator, Denominator>) noexcept;
}

template <std :: intmax_t Numerator, std :: intmax_t Denominator>
inline constexpr typename crap :: ceilType <std :: ratio<Numerator, Denominator> > :: type
crap :: ceil(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif
