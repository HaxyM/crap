#ifndef CRAP_BIT_BITFLOORVALUE
#define CRAP_BIT_BITFLOORVALUE

#include "../utility.d/language.h"

#include <type_traits>

#if CPP20
#include <bit>
#else
#include "bitwidthvalue.h"
#include "../numbers.d/zero.h"
#include <cstddef>
#endif

namespace crap
{
#if CPP20
 template <class Type, Type Value>
	 using bitFloorValue = std :: integral_constant<std :: size_t, std :: bit_floor(Value)>;
#else
 template <class Type, Type Value> struct bitFloorValue
 {
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

#if CPP20
#else
template <class Type, Type Value>
inline constexpr crap :: bitFloorValue <Type, Value> :: operator
typename crap :: bitFloorValue <Type, Value> :: value_type () const noexcept
{
 return crap :: bitFloorValue <Type, Value> :: value;
}
#endif
#endif

