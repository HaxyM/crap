#ifndef CRAP_BIT_POPCOUNTVALUE
#define CRAP_BIT_POPCOUNTVALUE

#include "../utility.d/language.h"

#include <cstddef>

#if CPP20
#include <bit>
#include <type_traits>
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
	 using popcountValue = std :: integral_constant<std :: size_t, std :: popcount(Value)>;
#else
 template <class Type, Type Value> struct popcountValue
 {
  private:
  constexpr const static Type any = zero <Type> :: value;
  constexpr const static Type zeros = any ^ any;
  constexpr const static Type ones = ~zeros;
  constexpr const static Type one = (~(ones << 1u)) & ones;
  constexpr const static std :: size_t bits = CHAR_BIT * sizeof(Type);
  template <std :: size_t ... Indices>
	  using sum = plusValue<std :: size_t, ((((one << Indices) & Value) == zeros) ? 0u : 1u)...>;
  public:
  constexpr const static std :: size_t value = iotaValue <bits, std :: size_t> :: template type <sum> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
#endif
}

#if CPP20
#else
template <class Type, Type Value>
inline constexpr crap :: popcountValue <Type, Value> :: operator
typename crap :: popcountValue <Type, Value> :: value_type () const noexcept
{
 return crap :: popcountValue <Type, Value> :: value;
}
#endif
#endif
