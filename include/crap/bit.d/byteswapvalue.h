#ifndef CRAP_BIT_BYTESWAPVALUE
#define CRAP_BIT_BYTESWAPVALUE

#include "../version.d/libbyteswap.h"

#include <cstddef>
#include <type_traits>

#if (crap_lib_byteswap >= 202110L)
#include <bit>
#else
#include "rotrvalue.h"
#include "../functional.d/bitwiseorvalue.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/iotavalue.h"
#include <climits>
#endif

namespace crap
{
#if (crap_lib_byteswap >= 202110L)
 template <class Type, Type Value>
	 using byteswapValue = std :: integral_constant<Type, std :: byteswap<Type>(Value)>;
#else
 template <class Type, Type Value> struct byteswapValue
 {
  private:
  constexpr const static Type any = zero <Type> :: value;
  constexpr const static Type zeros = any ^ any;
  constexpr const static Type ones = ~zeros;
  constexpr const static Type byteMask = ~((ones << CHAR_BIT) & ones);
  template <std :: size_t N>
	  using byte = rotrValue<N * CHAR_BIT, Type, (byteMask << (CHAR_BIT * N)) & Value>;
  template <std :: size_t ... Ns>
	  using combinator = bitwiseOrValue<Type, (byte <Ns> :: value << ((sizeof(Type) - Ns - 1u) * CHAR_BIT))...>;
  public:
  constexpr const static Type value =
	  iotaValue <sizeof(Type), std :: size_t> :: template type <combinator> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
#endif
}

#if (crap_lib_byteswap >= 202110L)
#else
template <class Type, Type Value>
inline constexpr crap :: byteswapValue <Type, Value> :: operator
typename crap :: byteswapValue <Type, Value> :: value_type () const noexcept
{
 return crap :: byteswapValue <Type, Value> :: value;
}
#endif
#endif

