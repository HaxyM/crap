#ifndef CRAP_BIT_ROTRVALUE
#define CRAP_BIT_ROTRVALUE

#include "../version.d/libbitops.h"

#include <cstddef>
#include <type_traits>

#if (crap_lib_bitops >= 201907L)
#include <bit>
#else
#include "../numbers.d/zero.h"
#include <climits>
#endif

namespace crap
{
#if (crap_lib_bitops >= 201907L)
 template <std :: size_t N, class Type, Type Value>
	 using rotrValue = std :: integral_constant<Type, std :: rotr<Type>(Value, N)>;
#else
 template <std :: size_t N, class Type, Type Value> struct rotrValue
 {
  private:
  constexpr const static std :: size_t bits = CHAR_BIT * sizeof(Type);
  constexpr const static std :: size_t shift = N % bits;
  constexpr const static Type any = zero <Type> :: value;
  constexpr const static Type zeros = any ^ any;
  constexpr const static Type ones = ~zeros;
  constexpr const static Type leftMask = (shift != 0u) ? ((ones << (bits - shift)) & ones) : zeros;
  constexpr const static Type rightMask = ~leftMask;
  constexpr const static Type left = (shift != 0u) ? ((Value << (bits - shift)) & leftMask) : zeros;
  constexpr const static Type right = (Value >> shift) & rightMask;
  public:
  constexpr const static Type value = (left | right);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
#endif
}

#if (crap_lib_bitops >= 201907L)
#else
template <std :: size_t N, class Type, Type Value>
inline constexpr crap :: rotrValue <N, Type, Value> :: operator
typename crap :: rotrValue <N, Type, Value> :: value_type () const noexcept
{
 return crap :: rotrValue <N, Type, Value> :: value;
}
#endif
#endif

