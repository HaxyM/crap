#ifndef CRAP_NUMERIC_ACCUMULATEVALUE
#define CRAP_NUMERIC_ACCUMULATEVALUE

#include <type_traits>

#include "../version.d/consteval.h"
#include "../version.d/implreflection.h"
#include "../version.d/libconstexprnumeric.h"
#include "../version.d/libintegralconstantcallable.h"

#if (crap_consteval >= 202211L) \
 && (crap_impl_reflection >= 202506L) \
 && (crap_lib_constexpr_numeric >= 201911L)
#include <meta>
#include <numeric>
#else
#include "../utility.d/bisectvalue.h"
#endif

namespace crap
{
 template <class Type, template <Type...> class, Type...> struct accumulateValue;

#if (crap_consteval >= 202211L) \
 && (crap_impl_reflection >= 202506L) \
 && (crap_lib_constexpr_numeric >= 201911L)
 template <class Type, template <Type...> class Operator> struct accumulateValue<Type, Operator>
	 : std :: integral_constant<decltype(Operator <> :: value), Operator <> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value>
	 struct accumulateValue<Type, Operator, Value>
	 : std :: integral_constant<decltype(Operator <Value> :: value), Operator <Value> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type ... Rest>
	 struct accumulateValue<Type, Operator, Value1, Value2, Rest...>
 {
  private:
  struct result_t;
  consteval static result_t findValue(std :: meta :: info searched) noexcept;
  consteval static result_t reduce(Type lhs, Type rhs) noexcept;
  consteval static result_t accumulate() noexcept;
  constexpr const static result_t result = accumulate();
  static_assert(result.found, "Value not found!");
  public:
  constexpr const static Type value = result.value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type ... Rest>
	 struct accumulateValue <Type, Operator, Value1, Value2, Rest...> :: result_t
 {
  Type value;
  bool found;
 };
#else
 template <class Type, template <Type...> class Operator> struct accumulateValue<Type, Operator>
	 : std :: integral_constant<decltype(Operator <> :: value), Operator <> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value>
	 struct accumulateValue<Type, Operator, Value>
	 : std :: integral_constant<decltype(Operator <Value> :: value), Operator <Value> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value1, Type Value2>
	 struct accumulateValue<Type, Operator, Value1, Value2>
	 : std :: integral_constant<decltype(Operator <Value1, Value2> :: value), Operator <Value1, Value2> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type Value3>
	 struct accumulateValue<Type, Operator, Value1, Value2, Value3>
 {
  private:
  constexpr const static Type subResult = Operator <Value1, Value2> :: value;
  public:
  constexpr const static Type value = Operator <subResult, Value3> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };

 template <class Type, template <Type...> class Operator, Type ... Values> struct accumulateValue
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using firstHalf = accumulateValue<Type, Operator, SubValues...>;
  constexpr const static Type firstHalfValue = values :: template lower <firstHalf> :: value;
  template <Type ... SubValues> using secondHalf = accumulateValue<Type, Operator, firstHalfValue, SubValues...>;
  public:
  constexpr const static Type value = values :: template upper <secondHalf> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
#endif
}

#if (crap_consteval >= 202211L) \
 && (crap_impl_reflection >= 202506L) \
 && (crap_lib_constexpr_numeric >= 201911L)
template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type ... Rest>
	inline consteval typename crap :: accumulateValue <Type, Operator, Value1, Value2, Rest...> :: result_t
	crap :: accumulateValue <Type, Operator, Value1, Value2, Rest...> :: findValue(std :: meta :: info searched)
	noexcept
{
 while (std :: meta :: is_type_alias(searched))
 {
  searched = std :: meta :: dealias(searched);
 }
 for (const auto field : std :: meta :: static_data_members_of(searched, std :: meta :: access_context :: current()))
 {
  if (std :: meta :: has_identifier(field) && (std :: meta :: identifier_of(field) == "value"))
  {
   return {std :: meta :: extract<Type>(field), true}; 
  }
 }
 for (const auto base : std :: meta :: bases_of(searched, std :: meta :: access_context :: current()))
 {
  const auto result = findValue(std :: meta :: type_of(base));
  if (result.found)
  {
   return result;
  }
 }
 return {Value1, false};
}

template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type ... Rest>
	inline consteval typename crap :: accumulateValue <Type, Operator, Value1, Value2, Rest...> :: result_t
	crap :: accumulateValue <Type, Operator, Value1, Value2, Rest...> :: reduce(Type lhs, Type rhs) noexcept
{
 return findValue(std :: meta :: substitute(^^Operator,
 {
  std :: meta :: constant_of(^^lhs),
  std :: meta :: constant_of(^^rhs)
 }));
}

template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type ... Rest>
	inline consteval typename crap :: accumulateValue <Type, Operator, Value1, Value2, Rest...> :: result_t
	crap :: accumulateValue <Type, Operator, Value1, Value2, Rest...> :: accumulate() noexcept
{
 constexpr const static Type values [sizeof...(Rest) + 1u] = {Value2, Rest...};
 constexpr const static result_t init = {Value1, true};
 return std :: accumulate(values, values + sizeof...(Rest) + 1u, init, [] (result_t lhs, Type rhs)
 {
  if (!lhs.found)
  {
   return lhs;
  }
  return reduce(lhs.value, rhs);
 });
}

template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type ... Rest>
	inline constexpr crap :: accumulateValue <Type, Operator, Value1, Value2, Rest...> :: operator
	typename crap :: accumulateValue <Type, Operator, Value1, Value2, Rest...> :: value_type () const noexcept
{
 return crap :: accumulateValue <Type, Operator, Value1, Value2, Rest...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type ... Rest>
inline constexpr typename crap :: accumulateValue <Type, Operator, Value1, Value2, Rest...> :: value_type
crap :: accumulateValue <Type, Operator, Value1, Value2, Rest...> :: operator () () const noexcept
{
 return crap :: accumulateValue <Type, Operator, Value1, Value2, Rest...> :: value;
}
#endif
#else
template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type Value3>
	inline constexpr crap :: accumulateValue <Type, Operator, Value1, Value2, Value3> :: operator
	typename crap :: accumulateValue <Type, Operator, Value1, Value2, Value3> :: value_type () const noexcept
{
 return crap :: accumulateValue <Type, Operator, Value1, Value2, Value3> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type Value3>
inline constexpr typename crap :: accumulateValue <Type, Operator, Value1, Value2, Value3> :: value_type
crap :: accumulateValue <Type, Operator, Value1, Value2, Value3> :: operator () () const noexcept
{
 return crap :: accumulateValue <Type, Operator, Value1, Value2, Value3> :: value;
}
#endif

template <class Type, template <Type...> class Operator, Type ... Values>
	inline constexpr crap :: accumulateValue <Type, Operator, Values...> :: operator
	typename crap :: accumulateValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: accumulateValue <Type, Operator, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type...> class Operator, Type ... Values>
inline constexpr typename crap :: accumulateValue <Type, Operator, Values...> :: value_type
crap :: accumulateValue <Type, Operator, Values...> :: operator () () const noexcept
{
 return crap :: accumulateValue <Type, Operator, Values...> :: value;
}
#endif
#endif
#endif

