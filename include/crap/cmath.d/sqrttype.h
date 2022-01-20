#ifndef CRAP_CMATH_SQRTTYPE
#define CRAP_CMATH_SQRTTYPE

#include "../functional.d/dividestype.h"
#include "../functional.d/minustype.h"
#include "../functional.d/multipliestype.h"
#include "../functional.d/plustype.h"

#include <cstddef>
#include <ratio>
#include <type_traits>

namespace crap
{
 template <class, std :: size_t Steps = 10u> struct sqrtType;

 template <intmax_t Numerator, intmax_t Denominator> struct sqrtType<std :: ratio<Numerator, Denominator>, 0u>
 {
  using type = std :: ratio<Numerator, Denominator>;
 };

 template <intmax_t Numerator, intmax_t Denominator, std :: size_t Steps>
	 struct sqrtType<std :: ratio<Numerator, Denominator>, Steps>
 {
  private:
  using z = std :: ratio<Numerator, Denominator>;
  using x = typename sqrtType <z, Steps - 1u> :: type;
  using partNum = typename minusType <typename multipliesType <x, x> :: type, z> :: type;
  using part = typename dividesType <partNum, typename plusType <x, x> :: type> :: type;
  public:
  using type = typename minusType <x, part> :: type;
 };

 template <intmax_t Numerator, intmax_t Denominator>
	 constexpr typename sqrtType <std :: ratio<Numerator, Denominator> > :: type
	 sqrt(std :: ratio<Numerator, Denominator>) noexcept;
}

template <intmax_t Numerator, intmax_t Denominator>
inline constexpr typename crap :: sqrtType <std :: ratio<Numerator, Denominator> > :: type
crap :: sqrt(std :: ratio<Numerator, Denominator>) noexcept
{
 return {};
}
#endif

