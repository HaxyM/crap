#ifndef CRAP_BIT_BITCEILVALUE
#define CRAP_BIT_BITCEILVALUE

#include "../version.d/libintpow2.h"

#include <type_traits>

#if (crap_lib_int_pow2 >= 202002L)
#include <bit>
#else
#include <climits>
#include <cstddef>

#include "bitfloorvalue.h"
#include "hassinglebitvalue.h"
#include "../numbers.d/zero.h"
#include "../version.d/char8t.h"
#include "../version.d/unicodecharacters.h"
#endif

namespace crap
{
#if (crap_lib_int_pow2 >= 202002L)
 template <class Type, Type Value>
	 using bitCeilValue = std :: integral_constant<Type, std :: bit_ceil<Type>(Value)>;
#else
 template <class Type, Type Value> struct bitCeilValue
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
  constexpr const static std :: size_t bits = CHAR_BIT * sizeof(Type);
  constexpr const static Type maxPower = (one << (bits - 1u)) & ones;
  constexpr const static std :: size_t floor = bitFloorValue <Type, Value> :: value;
  constexpr const static std :: size_t shift = hasSingleBitValue <Type, Value> :: value ? 0u : 1u;
  public:
  constexpr const static Type value =
	  ((floor == maxPower) && (shift == 1u)) ? zero : ((floor == zero) ? one : ((floor << shift) & ones));
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
#endif
}

#if (crap_lib_int_pow2 >= 202002L)
#else
template <class Type, Type Value>
inline constexpr crap :: bitCeilValue <Type, Value> :: operator
typename crap :: bitCeilValue <Type, Value> :: value_type () const noexcept
{
 return crap :: bitCeilValue <Type, Value> :: value;
}
#endif
#endif

