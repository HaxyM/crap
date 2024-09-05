#ifndef CRAP_BIT_BITWIDTHVALUE
#define CRAP_BIT_BITWIDTHVALUE

#include "../version.d/libintpow2.h"

#include <cstddef>
#include <type_traits>

#if (crap_lib_int_pow2 >= 202002L)
#include <bit>
#else
#include <climits>

#include "../functional.d/plusvalue.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/iotavalue.h"
#include "../version.d/char8t.h"
#include "../version.d/unicodecharacters.h"
#endif

namespace crap
{
#if (crap_lib_int_pow2 >= 202002L)
 template <class Type, Type Value>
	 using bitWidthValue = std :: integral_constant<std :: size_t, std :: bit_width(Value)>;
#else
 template <class Type, Type Value> struct bitWidthValue
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
  constexpr const static Type zeros = any ^ any;
  constexpr const static Type ones = ~zeros;
  constexpr const static std :: size_t bits = CHAR_BIT * sizeof(Type);
  template <std :: size_t ... Indices>
	  using sum = plusValue<std :: size_t, ((((ones << Indices) & Value) != zeros) ? 1u : 0u)...>;
  public:
  constexpr const static std :: size_t value = iotaValue <bits, std :: size_t> :: template type <sum> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
#endif
}

#if (crap_lib_int_pow2 >= 202002L)
#else
template <class Type, Type Value>
inline constexpr crap :: bitWidthValue <Type, Value> :: operator
typename crap :: bitWidthValue <Type, Value> :: value_type () const noexcept
{
 return crap :: bitWidthValue <Type, Value> :: value;
}
#endif
#endif

