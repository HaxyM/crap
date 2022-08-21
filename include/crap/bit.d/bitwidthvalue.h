#ifndef CRAP_BIT_BITWIDTHVALUE
#define CRAP_BIT_BITWIDTHVALUE

#include "../utility.d/language.h"

#include <cstddef>
#include <type_traits>

#if CPP20
#include <bit>
#else
#include "../functional.d/plusvalue.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/iotavalue.h"
#include <climits>
#endif

namespace crap
{
#if CPP20
 template <class Type, Type Value>
	 using bitWidthValue = std :: integral_constant<std :: size_t, std :: bit_width(Value)>;
#else
 template <class Type, Type Value> struct bitWidthValue
 {
  private:
  constexpr const static std :: size_t any = zero <std :: size_t> :: value;
  constexpr const static std :: size_t zero = any ^ any;
  constexpr const static std :: size_t bits = CHAR_BIT * sizeof(Type);
  template <std :: size_t ... Indices>
	  using sum = plusValue<std :: size_t, (((((~zero) << Indices) & Value) != zero) ? 1u : 0u)...>;
  public:
  constexpr const static std :: size_t value = iotaValue <bits, std :: size_t> :: template type <sum> :: value;
 };
#endif
}
#endif

