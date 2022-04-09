#ifndef CRAP_CMATH_TRUNCTYPE
#define CRAP_CMATH_TRUNCTYPE

#include <cstdint>
#include <ratio>

namespace crap
{
 template <class> struct truncType;

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct truncType<std :: ratio<Numerator, Denominator> >
 {
  private:
  using value = std :: ratio<Numerator, Denominator>;
  public:
  using type = std :: ratio<(value :: num / value :: den), 1>;
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 constexpr typename truncType <std :: ratio<Numerator, Denominator> > :: type
	 trunc(std :: ratio<Numerator, Denominator>) noexcept;
}

template <std :: intmax_t Numerator, std :: intmax_t Denominator>
inline constexpr typename crap :: truncType <std :: ratio<Numerator, Denominator> > :: type
crap :: trunc(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif
