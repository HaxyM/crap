#ifndef CRAP_BIT_COUNTLZEROVALUE
#define CRAP_BIT_COUNTLZEROVALUE

#include "../version.d/libbitops.h"

#include <cstddef>
#include <type_traits>

#if (crap_lib_bitops >= 201907L)
#include <bit>
#else
#include <climits>

#include "bitwidthvalue.h"
#include "../version.d/char8t.h"
#include "../version.d/libintegralconstantcallable.h"
#include "../version.d/unicodecharacters.h"
#endif

namespace crap
{
#if (crap_lib_bitops >= 201907L)
 template <class Type, Type Value>
	 using countlZeroValue = std :: integral_constant<std :: size_t, std :: countl_zero<Type>(Value)>;
#else
 template <class Type, Type Value> struct countlZeroValue
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
  constexpr const static std :: size_t width = bitWidthValue <Type, Value> :: value;
  public:
  constexpr const static std :: size_t value = bits - width;
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
template <class Type, Type Value>
inline constexpr crap :: countlZeroValue <Type, Value> :: operator
typename crap :: countlZeroValue <Type, Value> :: value_type () const noexcept
{
 return crap :: countlZeroValue <Type, Value> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type Value>
inline constexpr typename crap :: countlZeroValue <Type, Value> :: value_type
crap :: countlZeroValue <Type, Value> :: operator () () const noexcept
{
 return crap :: countlZeroValue <Type, Value> :: value;
}
#endif
#endif
#endif

