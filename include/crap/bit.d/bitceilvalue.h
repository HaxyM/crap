#ifndef CRAP_BIT_BITCEILVALUE
#define CRAP_BIT_BITCEILVALUE

#include "../utility.d/language.h"

#include <type_traits>

#if CPP20
#include <bit>
#else
#include "bitfloorvalue.h"
#include "hassinglebitvalue.h"
#include "../numbers.d/zero.h"
#include <climits>
#include <cstddef>
#endif

namespace crap
{
#if CPP20
 template <class Type, Type Value>
	 using bitCeilValue = std :: integral_constant<Type, std :: bit_ceil<Type>(Value)>;
#else
 template <class Type, Type Value> struct bitCeilValue
 {
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

#if CPP20
#else
template <class Type, Type Value>
inline constexpr crap :: bitCeilValue <Type, Value> :: operator
typename crap :: bitCeilValue <Type, Value> :: value_type () const noexcept
{
 return crap :: bitCeilValue <Type, Value> :: value;
}
#endif
#endif

