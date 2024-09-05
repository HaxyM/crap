#ifndef CRAP_BIT_ROTRVALUE
#define CRAP_BIT_ROTRVALUE

#include "../version.d/libbitops.h"

#include <cstddef>
#include <type_traits>

#if (crap_lib_bitops >= 201907L)
#include <bit>
#else
#include <climits>

#include "../numbers.d/zero.h"
#include "../version.d/char8t.h"
#include "../version.d/unicodecharacters.h"
#endif

namespace crap
{
#if (crap_lib_bitops >= 201907L)
 template <std :: size_t N, class Type, Type Value>
	 using rotrValue = std :: integral_constant<Type, std :: rotr<Type>(Value, N)>;
#else
 template <std :: size_t N, class Type, Type Value> struct rotrValue
 {
  static_assert((std :: is_integral <Type> :: value) && (std :: is_unsigned <Type> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, bool> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char> :: value) &&
#if (crap_char8_t >= 201811L)
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char8_t> :: value) &&
#endif
#if (crap_unicode_characters >= 200704L)
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char16_t> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, char32_t> :: value) &&
#endif
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, wchar_t> :: value),
		  "Unsupported type.");
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

