#ifndef CRAP_BIT_COUNTLZEROVALUE
#define CRAP_BIT_COUNTLZEROVALUE

#include "../version.d/libbitops.h"

#include <cstddef>
#include <type_traits>

#if (crap_lib_bitops >= 201907L)
#include <bit>
#else
#include "bitwidthvalue.h"
#include <climits>
#endif

namespace crap
{
#if (crap_lib_bitops >= 201907L)
 template <class Type, Type Value>
	 using countlZeroValue = std :: integral_constant<std :: size_t, std :: countl_zero<Type>(Value)>;
#else
 template <class Type, Type Value> struct countlZeroValue
 {
  private:
  constexpr const static std :: size_t bits = CHAR_BIT * sizeof(Type);
  constexpr const static std :: size_t width = bitWidthValue <Type, Value> :: value;
  public:
  constexpr const static std :: size_t value = bits - width;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
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
#endif
#endif

