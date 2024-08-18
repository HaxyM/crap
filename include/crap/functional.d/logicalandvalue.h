#ifndef CRAP_FUNCTIONAL_LOGICALANDVALUE
#define CRAP_FUNCTIONAL_LOGICALANDVALUE

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
 template <class Type, Type...> struct logicalAndValue;

 template <class Type> struct logicalAndValue<Type>
	 : std :: integral_constant<Type, identity <Type> :: value> {};

 template <class Type, Type Value> struct logicalAndValue<Type, Value>
	 : std :: integral_constant<Type, Value> {};

 template <class Type, Type Value1, Type Value2> struct logicalAndValue<Type, Value1, Value2>
	 : std :: integral_constant<Type, (Value1 && Value2)> {};

#if (crap_fold_expressions >= 201603L)
 template <class Type, Type ... Values> struct logicalAndValue
	 : std :: integral_constant<Type, (Values && ...)> {};
#else
 template <class Type, Type ... Values> struct logicalAndValue
 {
  private:
  template <Type ... SubValues> using This = logicalAndValue<Type, SubValues...>;
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
inline constexpr crap :: logicalAndValue <Type, Values...> :: operator
typename crap :: logicalAndValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: logicalAndValue <Type, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type ... Values>
inline constexpr typename crap :: logicalAndValue <Type, Values...> :: value_type
crap :: logicalAndValue <Type, Values...> :: operator () () const noexcept
{
 return crap :: logicalAndValue <Type, Values...> :: value;
}
#endif
#endif
#endif

