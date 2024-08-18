#ifndef CRAP_FUNCTIONAL_PLUSVALUE
#define CRAP_FUNCTIONAL_PLUSVALUE

#include <type_traits>

#include "../numbers.d/zero.h"
#include "../version.d/foldexpressions.h"

#if (crap_fold_expressions >= 201603L)
#else
#include "../numeric.d/reducevalue.h"
#include "../version.d/libintegralconstantcallable.h"
#endif

namespace crap
{
 template <class Type, Type...> struct plusValue;

 template <class Type> struct plusValue<Type>
	 : std :: integral_constant<Type, zero <Type> :: value> {};

 template <class Type, Type Value> struct plusValue<Type, Value>
	 : std :: integral_constant<Type, Value> {};
 
 template <class Type, Type Value1, Type Value2> struct plusValue<Type, Value1, Value2>
	 : std :: integral_constant<Type, (Value1 + Value2)> {};

#if (crap_fold_expressions >= 201603L)
 template <class Type, Type ... Values> struct plusValue
	 : std :: integral_constant<Type, (Values + ...)> {};
#else
 template <class Type, Type ... Values> struct plusValue
 {
  private:
  template <Type ... SubValues> using This = plusValue<Type, SubValues...>;
  public:
  constexpr const static auto value = reduceValue <Type, This, Values...> :: value;
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

template <class Type, Type ... Values>
inline constexpr crap :: plusValue <Type, Values...> :: operator
typename crap :: plusValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: plusValue <Type, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type ... Values>
inline constexpr typename crap :: plusValue <Type, Values...> :: value_type
crap :: plusValue <Type, Values...> :: operator () () const noexcept
{
 return crap :: plusValue <Type, Values...> :: value;
}
#endif
#endif
#endif

