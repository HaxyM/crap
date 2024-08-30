#ifndef CRAP_NUMERIC_LCMVALUE
#define CRAP_NUMERIC_LCMVALUE

#include <type_traits>

#include "../numbers.d/identity.h"
#include "../version.d/libgcdlcm.h"
#include "../version.d/libintegralconstantcallable.h"
#include "reducevalue.h"

#if (crap_lib_gcd_lcm >= 201606L)
#include <numeric>
#else
#include "gcdvalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct lcmValue;

 template <class Type>
	 struct lcmValue<Type> : std :: integral_constant<Type, identity <Type> :: value>
 {
  static_assert((std :: is_integral <Type> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, bool> :: value),
		  "Unsupported type.");
 };

 template <class Type, Type Value>
	 struct lcmValue<Type, Value> : std :: integral_constant<Type, Value>
 {
  static_assert((std :: is_integral <Type> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, bool> :: value),
		  "Unsupported type.");
 };

#if (crap_lib_gcd_lcm >= 201606L)
 template <class Type, Type Value1, Type Value2>
	 struct lcmValue<Type, Value1, Value2>
	 : std :: integral_constant<Type, std :: lcm(Value1, Value2)> {};
#else
 template <class Type, Type Value1, Type Value2> struct lcmValue<Type, Value1, Value2>
 {
  static_assert((std :: is_integral <Type> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, bool> :: value),
		  "Unsupported type.");
  private:
  constexpr const static auto Gcd = gcdValue <Type, Value1, Value2> :: value;
  public:
  constexpr const static Type value = (Value1 / Gcd) * Value2;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
#endif

 template <class Type, Type ... Values> struct lcmValue
 {
  static_assert((std :: is_integral <Type> :: value) &&
		  !(std :: is_same <typename std :: remove_cv <Type> :: type, bool> :: value),
		  "Unsupported type.");
  private:
  template <Type ... SubValues> using This = lcmValue<Type, SubValues...>;
  public:
  constexpr const static Type value = reduceValue <Type, This, Values...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}
#if (crap_lib_gcd_lcm >= 201606L)
#else

template <class Type, Type Value1, Type Value2>
	inline constexpr crap :: lcmValue <Type, Value1, Value2> :: operator
	typename crap :: lcmValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: lcmValue <Type, Value1, Value2> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type Value1, Type Value2>
inline constexpr typename crap :: lcmValue <Type, Value1, Value2> :: value_type
crap :: lcmValue <Type, Value1, Value2> :: operator () () const noexcept
{
 return crap :: lcmValue <Type, Value1, Value2> :: value;
}
#endif
#endif

template <class Type, Type ... Values>
	inline constexpr crap :: lcmValue <Type, Values...> :: operator
	typename crap :: lcmValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: lcmValue <Type, Values...> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type ... Values>
inline constexpr typename crap :: lcmValue <Type, Values...> :: value_type
crap :: lcmValue <Type, Values...> :: operator () () const noexcept
{
 return crap :: lcmValue <Type, Values...> :: value;
}
#endif
#endif

