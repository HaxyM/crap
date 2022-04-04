#ifndef CRAP_CMATH_FLOORTYPE
#define CRAP_CMATH_FLOORTYPE

#include <cstdint>
#include <ratio>

namespace crap
{
 template <class> struct floorType;

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct floorType<std :: ratio<Numerator, Denominator> >
 {
  private:
  using value = std :: ratio<Numerator, Denominator>;
  constexpr const static bool whole = ((value :: num % value :: den) == 0);
  constexpr const static bool positive = ((value :: num < 0) == ( value :: den < 0));
  constexpr const static std :: intmax_t newNum = value :: num / value :: den;
  public:
  using type = std :: ratio<((whole || positive) ? newNum : (newNum - 1)), 1>;
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 constexpr typename floorType <std :: ratio<Numerator, Denominator> > :: type
	 floor(std :: ratio<Numerator, Denominator>) noexcept;
}

template <std :: intmax_t Numerator, std :: intmax_t Denominator>
inline constexpr typename crap :: floorType <std :: ratio<Numerator, Denominator> > :: type
crap :: floor(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif
