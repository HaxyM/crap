#ifndef CRAP_BIT_POPCOUNTVALUE
#define CRAP_BIT_POPCOUNTVALUE

#include "../utility.d/language.h"

#include <cstddef>

#if CPP20
#include <bit>
#include <type_traits>
#else
#include "../functional.d/plusvalue.h"
#include "../numbers.d/zero.h"
#include "../numeric.d/iotavalue.h"
#include <climits>
#endif

namespace crap
{
#if CPP20
 template <class Type, Type Value>
	 using popcountValue = std :: integral_constant<std :: size_t, std :: popcount(Value)>;
#else
 template <class Type, Type Value> struct popcountValue
 {
  private:
  constexpr const static std :: size_t any = zero <std :: size_t> :: value;
  constexpr const static std :: size_t zero = any ^ any;
  constexpr const static std :: size_t one = ~((~zero) << 1u);
  constexpr const static std :: size_t bits = CHAR_BIT * sizeof(Type);
  template <std :: size_t ... Indices>
	  using sum = plusValue<std :: size_t, ((((one << Indices) & Value) == zero) ? 0u : 1u)...>;
  public:
  constexpr const static std :: size_t value = iotaValue <bits, std :: size_t> :: template type <sum> :: value;
 };
#endif
}
#endif

