#ifndef CRAP_FUNCTIONAL_MULTIPLIESVALUE
#define CRAP_FUNCTIONAL_MULTIPLIESVALUE

#include <type_traits>

#include "../numbers.d/identity.h"
#include "../version.d/foldexpressions.h"

#if (crap_fold_expressions >= 201603L)
#else
#include "../numeric.d/reducevalue.h"
#include "../version.d/libintegralconstantcallable.h"
#endif

namespace crap
{
 template <class Type, Type...> struct multipliesValue;

 template <class Type> struct multipliesValue<Type>
	 : std :: integral_constant<Type, identity <Type> :: value> {};

 template <class Type, Type Value> struct multipliesValue<Type, Value>
	 : std :: integral_constant<Type, Value> {};

 template <class Type, Type Value1, Type Value2> struct multipliesValue<Type, Value1, Value2>
	 : std :: integral_constant<Type, (Value1 * Value2)> {};

#if (crap_fold_expressions >= 201603L)
 template <class Type, Type ... Values> struct multipliesValue
	 : std :: integral_constant<Type, (Values * ...)> {};
#else
 template <class Type, Type ... Values> struct multipliesValue
 {
  private:
  template <Type ... SubValues> using This = multipliesValue<Type, SubValues...>;
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
inline constexpr crap :: multipliesValue <Type, Values...> :: operator
typename crap :: multipliesValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: multipliesValue <Type, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type ... Values>
inline constexpr typename crap :: multipliesValue <Type, Values...> :: value_type
crap :: multipliesValue <Type, Values...> :: operator () () const noexcept
{
 return crap :: multipliesValue <Type, Values...> :: value;
}
#endif
#endif
#endif

