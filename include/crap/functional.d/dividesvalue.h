#ifndef CRAP_FUNCTIONAL_DIVIDESVALUE
#define CRAP_FUNCTIONAL_DIVIDESVALUE

#include <type_traits>

#include "../version.d/foldexpressions.h"

#if (crap_fold_expressions >= 201603L)
#else
#include "../numeric.d/accumulatevalue.h"
#include "../version.d/libintegralconstantcallable.h"
#endif

namespace crap
{
 template <class Type, Type...> struct dividesValue;

 template <class Type, Type Value> struct dividesValue<Type, Value>
	 : std :: integral_constant<Type, Value> {};

 template <class Type, Type Value1, Type Value2> struct dividesValue<Type, Value1, Value2>
	 : std :: integral_constant<Type, (Value1 / Value2)> {};

#if (crap_fold_expressions >= 201603L)
 template <class Type, Type FirstValue, Type ... Rest> struct dividesValue<Type, FirstValue, Rest...>
	 : std :: integral_constant<Type, (FirstValue / ... / Rest)> {};
#else
 template <class Type, Type FirstValue, Type ... Rest> struct dividesValue<Type, FirstValue, Rest...>
 {
  private:
  template <Type ... SubValues> using This = dividesValue<Type, SubValues...>;
  public:
  constexpr const static auto value = accumulateValue <Type, This, FirstValue, Rest...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
#endif
}

#if (crap_fold_expressions >= 201603L)
#else
template <class Type, Type FirstValue, Type ... Rest>
inline constexpr crap :: dividesValue <Type, FirstValue, Rest...> :: operator
typename crap :: dividesValue <Type, FirstValue, Rest...> :: value_type () const noexcept
{
 return crap :: dividesValue <Type, FirstValue, Rest...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type FirstValue, Type ... Rest>
inline constexpr typename crap :: dividesValue <Type, FirstValue, Rest...> :: value_type
crap :: dividesValue <Type, FirstValue, Rest...> :: operator () () const noexcept
{
 return crap :: dividesValue <Type, FirstValue, Rest...> :: value;
}
#endif
#endif
#endif

