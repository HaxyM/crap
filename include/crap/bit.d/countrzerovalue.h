#ifndef CRAP_BIT_COUNTRZEROVALUE
#define CRAP_BIT_COUNTRZEROVALUE

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
	 using countrZeroValue = std :: integral_constant<std :: size_t, std :: countr_zero(Value)>;
#else
 template <class Type, Type Value> struct countrZeroValue
 {
  private:
  constexpr const static Type any = zero <Type> :: value;
  constexpr const static Type zeros = any ^ any;
  constexpr const static Type ones = ~zeros;
  constexpr const static std :: size_t bits = CHAR_BIT * sizeof(Type);
  template <std :: size_t ... Indices>
	  using sum = plusValue<std :: size_t, ((Value == zeros) ? 1u : 0u), (((~(ones << Indices) & Value) != zeros) ? 0u : 1u)...>;
  public:
  constexpr const static std :: size_t value = iotaValue <(bits - 1u), std :: size_t, 1u> :: template type <sum> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
#endif
}

#if CPP20
#else
template <class Type, Type Value>
inline constexpr crap :: countrZeroValue <Type, Value> :: operator
typename crap :: countrZeroValue <Type, Value> :: value_type () const noexcept
{
 return crap :: countrZeroValue <Type, Value> :: value;
}
#endif
#endif
