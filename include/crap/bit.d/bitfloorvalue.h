#ifndef CRAP_BIT_BITFLOORVALUE
#define CRAP_BIT_BITFLOORVALUE

#include "../version.d/libintpow2.h"

#include <type_traits>

#if (crap_lib_int_pow2 >= 202002L)
#include <bit>
#else
#include <cstddef>

#include "bitwidthvalue.h"
#include "../numbers.d/zero.h"
#include "../version.d/char8t.h"
#include "../version.d/unicodecharacters.h"
#endif

namespace crap
{
#if (crap_lib_int_pow2 >= 202002L)
 template <class Type, Type Value>
	 using bitFloorValue = std :: integral_constant<std :: size_t, std :: bit_floor(Value)>;
#else
 template <class Type, Type Value> struct bitFloorValue
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
  constexpr const static Type any = zero <Type> :: value;
  constexpr const static Type zero = any ^ any;
  constexpr const static Type ones = ~zero;
  constexpr const static Type one = (~(ones << 1u)) & ones;
  constexpr const static std :: size_t width = bitWidthValue <Type, Value> :: value;
  constexpr const static std :: size_t wLess = (width == 0u) ? 0u : (width - 1u);
  public:
  constexpr const static Type value = (width == 0u) ? zero : (one << wLess);
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
#endif
}

#if (crap_lib_int_pow2 >= 202002L)
#else
template <class Type, Type Value>
inline constexpr crap :: bitFloorValue <Type, Value> :: operator
typename crap :: bitFloorValue <Type, Value> :: value_type () const noexcept
{
 return crap :: bitFloorValue <Type, Value> :: value;
}
#endif
#endif

