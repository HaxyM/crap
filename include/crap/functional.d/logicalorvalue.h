#ifndef CRAP_FUNCTIONAL_LOGICALORVALUE
#define CRAP_FUNCTIONAL_LOGICALORVALUE

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
 template <class Type, Type...> struct logicalOrValue;

 template <class Type> struct logicalOrValue<Type>
	 : std :: integral_constant<Type, zero <Type> :: value> {};

 template <class Type, Type Value> struct logicalOrValue<Type, Value>
	 : std :: integral_constant<Type, Value> {};

 template <class Type, Type Value1, Type Value2> struct logicalOrValue<Type, Value1, Value2>
	 : std :: integral_constant<Type, (Value1 || Value2)> {};

#if (crap_fold_expressions >= 201603L)
 template <class Type, Type ... Values> struct logicalOrValue
	 : std :: integral_constant<Type, (Values || ...)> {};
#else
 template <class Type, Type ... Values> struct logicalOrValue
 {
  private:
  template <Type ... SubValues> using This = logicalOrValue<Type, SubValues...>;
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
inline constexpr crap :: logicalOrValue <Type, Values...> :: operator
typename crap :: logicalOrValue <Type, Values...> :: value_type () const noexcept
{
 return crap :: logicalOrValue <Type, Values...> :: value;
}
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, Type ... Values>
inline constexpr typename crap :: logicalOrValue <Type, Values...> :: value_type
crap :: logicalOrValue <Type, Values...> :: operator () () const noexcept
{
 return crap :: logicalOrValue <Type, Values...> :: value;
}
#endif
#endif
#endif

