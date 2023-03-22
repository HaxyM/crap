#ifndef CRAP_CMATH_MODFTYPE
#define CRAP_CMATH_MODFTYPE

#include <cstdint>
#include <ratio>

#include "trunctype.h"
#include "../functional.d/minustype.h"

namespace crap
{
 template <class> struct modfType;
 
 template <class Type> using modfType_t = typename modfType <Type> :: type;

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 struct modfType<std :: ratio<Numerator, Denominator> >
 {
  private:
  using value = std :: ratio<Numerator, Denominator>;
  public:
  using intPart = typename truncType <value> :: type;
  using type = typename minusType <value, intPart> :: type;
 };

 template <std :: intmax_t Numerator, std :: intmax_t Denominator>
	 constexpr typename modfType <std :: ratio<Numerator, Denominator> > :: type
	 modf(std :: ratio<Numerator, Denominator>) noexcept;
}

template <std :: intmax_t Numerator, std :: intmax_t Denominator>
inline constexpr typename crap :: modfType <std :: ratio<Numerator, Denominator> > :: type
crap :: modf(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif
