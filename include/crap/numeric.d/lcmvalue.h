#ifndef CRAP_NUMERIC_LCMVALUE
#define CRAP_NUMERIC_LCMVALUE

#include "../utility.d/language.h"
#include "reducevalue.h"
#include "identity.h"

#if CPP17
#include <numeric>
#else
#include "gcdvalue.h"
#include <type_traits>
#endif

namespace crap
{
 template <class Type, Type...> struct lcmValue;

 template <class Type> struct lcmValue<Type>
 {
  constexpr const static Type value = identity <Type> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value> struct lcmValue<Type, Value>
 {
  constexpr const static Type value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value1, Type Value2> struct lcmValue<Type, Value1, Value2>
 {
  #if CPP17
  constexpr const static Type value = std :: lcm(Value1, Value2);
  #else
  private:
  constexpr const static auto Gcd = gcdValue <Type, Value1, Value2> :: value;
  public:
  constexpr const static Type value = (Value1 / Gcd) * Value2;
  #endif
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type ... Values> struct lcmValue
 {
  private:
  template <Type ... SubValues> using This = lcmValue<Type, SubValues...>;
  public:
  constexpr const static Type value = reduceValue <Type, This, Values...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type>
	inline constexpr crap :: lcmValue <Type> :: operator
	typename crap :: lcmValue <Type> :: value_type () const noexcept
{
 return crap :: lcmValue <Type> :: value;
};

template <class Type, Type Value>
	inline constexpr crap :: lcmValue <Type, Value> :: operator
	typename crap :: lcmValue <Type, Value> :: value_type () const noexcept
{
 return crap :: lcmValue <Type, Value> :: value;
};

template <class Type, Type Value1, Type Value2>
	inline constexpr crap :: lcmValue <Type, Value1, Value2> :: operator
	typename crap :: lcmValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: lcmValue <Type, Value1, Value2> :: value;
};

template <class Type, Type ... Values>
	inline constexpr crap :: lcmValue <Type, Values...> :: operator
	typename crap :: lcmValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: lcmValue <Type, Values...> :: value;
};
#endif

