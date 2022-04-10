#ifndef CRAP_CMATH_SIGNBITTYPE
#define CRAP_CMATH_SIGNBITTYPE

#include <cstdint>
#include <ratio>
#include <type_traits>

namespace crap
{
 template <class> struct signbitType;

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct signbitType<std :: ratio<Numerator, Denominator> >
	 : std :: integral_constant<bool, (Numerator < 0) != (Denominator < 0)>{};

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 constexpr bool signbit(std :: ratio<Numerator, Denominator>) noexcept;
}

template <std :: intmax_t Numerator, std :: intmax_t Denominator>
inline constexpr bool crap :: signbit(std :: ratio<Numerator, Denominator>) noexcept
{
 return crap :: signbitType <std :: ratio<Numerator, Denominator> > :: value;
}
#endif
