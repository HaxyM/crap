#ifndef CRAP_BIT_ROTLVALUE
#define CRAP_BIT_ROTLVALUE

#include "../version.d/libbitops.h"

#include <cstddef>
#include <type_traits>

#if (crap_lib_bitops >= 201907L)
#include <bit>
#else
#include <climits>

#include "../numbers.d/zero.h"
#include "../version.d/char8t.h"
#include "../version.d/libintegralconstantcallable.h"
#include "../version.d/unicodecharacters.h"
#endif

namespace crap
{
#if (crap_lib_bitops >= 201907L)
 template <std :: size_t N, class Type, Type Value>
	 using rotlValue = std :: integral_constant<Type, std :: rotl<Type>(Value, N)>;
#else
 template <std :: size_t N, class Type, Type Value> struct rotlValue
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
  constexpr const static Type leftMask = (ones << shift) & ones;
  constexpr const static Type rightMask = ~leftMask;
  constexpr const static Type left = (Value << shift) & leftMask;
  constexpr const static Type right = (Value >> (bits - shift)) & rightMask;
  public:
  constexpr const static Type value = (left | right);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
#endif
}

#if (crap_lib_bitops >= 201907L)
#else
template <std :: size_t N, class Type, Type Value>
inline constexpr crap :: rotlValue <N, Type, Value> :: operator
typename crap :: rotlValue <N, Type, Value> :: value_type () const noexcept
{
 return crap :: rotlValue <N, Type, Value> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <std :: size_t N, class Type, Type Value>
inline constexpr typename crap :: rotlValue <N, Type, Value> :: value_type
crap :: rotlValue <N, Type, Value> :: operator () () const noexcept
{
 return crap :: rotlValue <N, Type, Value> :: value;
}
#endif
#endif
#endif

