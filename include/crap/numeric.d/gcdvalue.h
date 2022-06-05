#ifndef CRAP_NUMERIC_GCDVALUE
#define CRAP_NUMERIC_GCDVALUE

#include "../utility.d/language.h"
#include "reducevalue.h"
#include "zero.h"

#if CPP17
#include <numeric>
#else
#include <type_traits>
#endif

namespace crap
{
 template <class Type, Type...> struct gcdValue;

 template <class Type> struct gcdValue<Type>
 {
  constexpr const static Type value = zero <Type> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value> struct gcdValue<Type, Value>
 {
  constexpr const static Type value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value> struct gcdValue<Type, Value, Value>
 {
  constexpr const static Type value = Value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type Value1, Type Value2> struct gcdValue<Type, Value1, Value2>
 {
  #if CPP17
  constexpr const static Type value = std :: gcd(Value1, Value2);
  #else
  private:
  constexpr const static Type
	  getValue(std :: integral_constant<Type, static_cast<Type>(0)>, std :: integral_constant<Type, static_cast<Type>(1)>);
  constexpr const static Type
	  getValue(std :: integral_constant<Type, static_cast<Type>(1)>, std :: integral_constant<Type, static_cast<Type>(0)>);
  template <Type SubValue> constexpr const static Type
	  getValue(std :: integral_constant<Type, SubValue>, std :: integral_constant<Type, static_cast<Type>(0)>);
  template <Type SubValue> constexpr const static Type
	  getValue(std :: integral_constant<Type, static_cast<Type>(0)>, std :: integral_constant<Type, SubValue>);
  template <Type SubValue> constexpr const static Type
	  getValue(std :: integral_constant<Type, SubValue>, std :: integral_constant<Type, static_cast<Type>(1)>);
  template <Type SubValue> constexpr const static Type
	  getValue(std :: integral_constant<Type, static_cast<Type>(1)>, std :: integral_constant<Type, SubValue>);
  template <Type SubValue> constexpr const static Type
	  getValue(std :: integral_constant<Type, SubValue>, std :: integral_constant<Type, SubValue>);
  template <Type SubValue1, Type SubValue2> constexpr const static Type
	  getValue(std :: integral_constant<Type, SubValue1>, std :: integral_constant<Type, SubValue2>);
  public:
  constexpr const static Type value =
	  getValue(std :: integral_constant<Type, Value1>{}, std :: integral_constant<Type, Value2>{});
  #endif
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };

 template <class Type, Type ... Values> struct gcdValue
 {
  private:
  template <Type ... SubValues> using This = gcdValue<Type, SubValues...>;
  public:
  constexpr const static Type value = reduceValue <Type, This, Values...> :: value;
 };
}

template <class Type>
	inline constexpr crap :: gcdValue <Type> :: operator
	typename crap :: gcdValue <Type> :: value_type () const noexcept
{
 return crap :: gcdValue <Type> :: value;
};

template <class Type, Type Value>
	inline constexpr crap :: gcdValue <Type, Value> :: operator
	typename crap :: gcdValue <Type, Value> :: value_type () const noexcept
{
 return crap :: gcdValue <Type, Value> :: value;
};

#if CPP17
#else
template <class Type, Type Value1, Type Value2> inline constexpr const Type
	crap :: gcdValue <Type, Value1, Value2> :: getValue(std :: integral_constant<Type, static_cast<Type>(0)>, std :: integral_constant<Type, static_cast<Type>(1)>)
{
 return static_cast<Type>(1);
}

template <class Type, Type Value1, Type Value2> inline constexpr const Type
	crap :: gcdValue <Type, Value1, Value2> :: getValue(std :: integral_constant<Type, static_cast<Type>(1)>, std :: integral_constant<Type, static_cast<Type>(0)>)
{
 return static_cast<Type>(1);
}

template <class Type, Type Value1, Type Value2> template <Type SubValue> inline constexpr const Type
	crap :: gcdValue <Type, Value1, Value2> :: getValue(std :: integral_constant<Type, SubValue>, std :: integral_constant<Type, static_cast<Type>(0)>)
{
 return SubValue;
}

template <class Type, Type Value1, Type Value2> template <Type SubValue> inline constexpr const Type
	crap :: gcdValue <Type, Value1, Value2> :: getValue(std :: integral_constant<Type, static_cast<Type>(0)>, std :: integral_constant<Type, SubValue>)
{
 return SubValue;
}

template <class Type, Type Value1, Type Value2> template <Type SubValue> inline constexpr const Type
	crap :: gcdValue <Type, Value1, Value2> :: getValue(std :: integral_constant<Type, SubValue>, std :: integral_constant<Type, static_cast<Type>(1)>)
{
 return static_cast<Type>(1);
}

template <class Type, Type Value1, Type Value2> template <Type SubValue> inline constexpr const Type
	crap :: gcdValue <Type, Value1, Value2> :: getValue(std :: integral_constant<Type, static_cast<Type>(1)>, std :: integral_constant<Type, SubValue>)
{
 return static_cast<Type>(1);
}

template <class Type, Type Value1, Type Value2> template <Type SubValue> inline constexpr const Type
	crap :: gcdValue <Type, Value1, Value2> :: getValue(std :: integral_constant<Type, SubValue>, std :: integral_constant<Type, SubValue>)
{
 return SubValue;
}

template <class Type, Type Value1, Type Value2> template <Type SubValue1, Type SubValue2> inline constexpr const Type
	crap :: gcdValue <Type, Value1, Value2> :: getValue(std :: integral_constant<Type, SubValue1>, std :: integral_constant<Type, SubValue2>)
{
 return crap :: gcdValue <Type, Value1, Value2> :: getValue(std :: integral_constant<Type, (SubValue1 < SubValue2) ? SubValue1 : (SubValue1 % SubValue2)>{}, std :: integral_constant<Type, (SubValue2 < SubValue1) ? SubValue2 : (SubValue2 % SubValue1)>{});
}
#endif

template <class Type, Type Value1, Type Value2>
	inline constexpr crap :: gcdValue <Type, Value1, Value2> :: operator
	typename crap :: gcdValue <Type, Value1, Value2> :: value_type () const noexcept
{
 return crap :: gcdValue <Type, Value1, Value2> :: value;
};

template <class Type, Type ... Values>
	inline constexpr crap :: gcdValue <Type, Values...> :: operator
	typename crap :: gcdValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: gcdValue <Type, Values...> :: value;
};
#endif
