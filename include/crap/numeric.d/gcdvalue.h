#ifndef CRAP_NUMERIC_GCDVALUE
#define CRAP_NUMERIC_GCDVALUE

#include <type_traits>

#include "../numbers.d/zero.h"
#include "../version.d/libgcdlcm.h"
#include "../version.d/libintegralconstantcallable.h"
#include "reducevalue.h"

#if (crap_lib_gcd_lcm >= 201606L)
#include <numeric>
#else
#include "../numbers.d/identity.h"
#endif

namespace crap
{
 template <class Type, Type...> struct gcdValue;

 template <class Type>
	 struct gcdValue<Type> : std :: integral_constant<Type, zero <Type> :: value>
 {
  static_assert((std :: is_integral <Type> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, bool> :: value),
		  "Unsupported type.");
 };

 template <class Type, Type Value>
	 struct gcdValue<Type, Value> : std :: integral_constant<Type, Value>
 {
  static_assert((std :: is_integral <Type> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, bool> :: value),
		  "Unsupported type.");
 };

#if (crap_lib_gcd_lcm >= 201606L)
 template <class Type, Type Value1, Type Value2>
	 struct gcdValue<Type, Value1, Value2>
	 : std :: integral_constant<Type, std :: gcd(Value1, Value2)> {};
#else
 template <class Type, Type Value>
	 struct gcdValue<Type, Value, Value> : std :: integral_constant<Type, Value> {};

 template <class Type, Type Value1, Type Value2> struct gcdValue<Type, Value1, Value2>
 {
  static_assert((std :: is_integral <Type> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, bool> :: value),
		  "Unsupported type.");
  private:
  constexpr const static Type const0 = zero <Type> :: value;
  constexpr const static Type const1 = identity <Type> :: value;
  constexpr const static bool nonTrivial =
	  ((Value1 != const0) && (Value2 != const0) && (Value1 != const1) && (Value2 != const1));
  template <bool NonTrivial, class ... Empty> struct Implementation;
  template <class ... Empty> struct Implementation<true, Empty...>;
  template <class ... Empty> struct Implementation<false, Empty...>;
  public:
  constexpr const static Type value = Implementation <nonTrivial> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
#endif

 template <class Type, Type ... Values> struct gcdValue
 {
  static_assert((std :: is_integral <Type> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, bool> :: value),
		  "Unsupported type.");
  private:
  template <Type ... SubValues> using This = gcdValue<Type, SubValues...>;
  public:
  constexpr const static Type value = reduceValue <Type, This, Values...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

#if (crap_lib_gcd_lcm >= 201606L)
#else
 template <class Type, Type Value1, Type Value2>
	 template <class ... Empty>
 struct gcdValue <Type, Value1, Value2> :: Implementation<true, Empty...>
 {
  private:
  constexpr const static Type newVal1 = ((Value1 < Value2) ? Value1 : (Value1 % Value2));
  constexpr const static Type newVal2 = ((Value2 < Value1) ? Value2 : (Value2 % Value1));
  public:
  constexpr const static Type value = gcdValue <Type, newVal1, newVal2> :: value;
 };

 template <class Type, Type Value1, Type Value2>

	 template <class ... Empty>
 struct gcdValue <Type, Value1, Value2> :: Implementation<false, Empty...>
 {
  private:
  constexpr const static Type const0 = zero <Type> :: value;
  constexpr const static Type const1 = identity <Type> :: value;
  constexpr const static bool any1 = ((Value1 == const1) || (Value2 == const1));
  constexpr const static bool val1non0 = (Value1 != const0);
  public:
  constexpr const static Type value = (any1 ? const1 : (val1non0 ? Value1 : Value2));
 };
#endif
}
#if (crap_lib_gcd_lcm >= 201606L)
#else

template <class Type, Type Value1, Type Value2>
	inline constexpr crap :: gcdValue <Type, Value1, Value2> :: operator
	typename crap :: gcdValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: gcdValue <Type, Value1, Value2> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type Value1, Type Value2>
inline constexpr typename crap :: gcdValue <Type, Value1, Value2> :: value_type
crap :: gcdValue <Type, Value1, Value2> :: operator () () const noexcept
{
 return crap :: gcdValue <Type, Value1, Value2> :: value;
}
#endif
#endif

template <class Type, Type ... Values>
	inline constexpr crap :: gcdValue <Type, Values...> :: operator
	typename crap :: gcdValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: gcdValue <Type, Values...> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type ... Values>
inline constexpr typename crap :: gcdValue <Type, Values...> :: value_type
crap :: gcdValue <Type, Values...> :: operator () () const noexcept
{
 return crap :: gcdValue <Type, Values...> :: value;
}
#endif
#endif

