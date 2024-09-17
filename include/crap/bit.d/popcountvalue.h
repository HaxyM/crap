#ifndef CRAP_BIT_POPCOUNTVALUE
#define CRAP_BIT_POPCOUNTVALUE

#include "../version.d/libbitops.h"

#include <cstddef>

#if (crap_lib_bitops >= 201907L)
#include <bit>
#include <type_traits>
#else
#include <climits>

#include "../functional.d/plusvalue.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/iotavalue.h"
#include "../version.d/char8t.h"
#include "../version.d/libintegralconstantcallable.h"
#include "../version.d/unicodecharacters.h"
#endif

namespace crap
{
#if (crap_lib_bitops >= 201907L)
 template <class Type, Type Value>
	 using popcountValue = std :: integral_constant<std :: size_t, std :: popcount(Value)>;
#else
 template <class Type, Type Value> struct popcountValue
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
  constexpr const static Type one = (~(ones << 1u)) & ones;
  constexpr const static std :: size_t bits = CHAR_BIT * sizeof(Type);
  template <std :: size_t ... Indices>
	  using sum = plusValue<std :: size_t, ((((one << Indices) & Value) == zeros) ? 0u : 1u)...>;
  public:
  constexpr const static std :: size_t value = iotaValue <bits, std :: size_t> :: template type <sum> :: value;
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
inline constexpr crap :: popcountValue <Type, Value> :: operator
typename crap :: popcountValue <Type, Value> :: value_type () const noexcept
{
 return crap :: popcountValue <Type, Value> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type Value>
inline constexpr typename crap :: popcountValue <Type, Value> :: value_type
crap :: popcountValue <Type, Value> :: operator () () const noexcept
{
 return crap :: popcountValue <Type, Value> :: value;
}
#endif
#endif
#endif

