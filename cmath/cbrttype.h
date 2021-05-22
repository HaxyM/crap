#ifndef CRAP_CMATH_CBRTTYPE
#define CRAP_CMATH_CBRTTYPE

#include "../functional/dividestype.h"
#include "../functional/minustype.h"
#include "../functional/multipliestype.h"
#include "../functional/plustype.h"

#include <cstddef>
#include <ratio>
#include <type_traits>

namespace crap
{
 template <class, std :: size_t Steps = 10u> struct cbrtType;

 template <intmax_t Numerator, intmax_t Denominator> struct cbrtType<std :: ratio<Numerator, Denominator>, 0u>
 {
  using type = std :: ratio<Numerator, Denominator>;
 };

 template <intmax_t Numerator, intmax_t Denominator, std :: size_t Steps>
	 struct cbrtType<std :: ratio<Numerator, Denominator>, Steps>
 {
  private:
  using z = std :: ratio<Numerator, Denominator>;
  using x = typename cbrtType <z, Steps - 1u> :: type;
  using x2 = typename multipliesType <x, x> :: type;
  using partNum = typename minusType <typename multipliesType <x, x, x> :: type, z> :: type;
  using part = typename dividesType <partNum, typename plusType <x2, x2, x2> :: type> :: type;
  public:
  using type = typename minusType <x, part> :: type;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename cbrtType <std :: ratio<Numerator, Denominator> > :: type
	 cbrt(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: cbrtType <std :: ratio<Numerator, Denominator> > :: type
crap :: cbrt(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

