#ifndef CRAP_NUMERIC_INNERPRODUCTVALUE
#define CRAP_NUMERIC_INNERPRODUCTVALUE

#include "reducevalue.h"
#include "../algorithm.d/transform2value.h"
#include "../version.d/libintegralconstantcallable.h"
#include "../version.d/variabletemplates.h"

namespace crap
{
 template <class Type, template <Type...> class AdditiveOperator, template <Type...> class MultiplicativeOperator, Type ... Values1>
 struct innerProductValue
 {
  template <Type ... Values2> struct with;
#if (crap_variable_templates >= 201304L)
  template <Type ... Values2> constexpr const static Type value = with <Values2...> :: value;
#endif
 };

 template <class Type, template <Type...> class AdditiveOperator, template <Type...> class MultiplicativeOperator, Type ... Values1>
	template <Type ... Values2>
 struct innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> :: with
 {
  private:
  template <Type A, Type B> using multiplicative = MultiplicativeOperator<A, B>;
  template <Type ... SubTypes> using Reductor = reduceValue<Type, AdditiveOperator, SubTypes...>;
  public:
  constexpr const static Type value = transform2Value <Type, multiplicative, Values1...> :: template
	  with <Values2...> :: template type <Reductor> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
#if (crap_lib_integral_constant_callable >= 201304L)
  constexpr value_type operator () () const noexcept;
#endif
 };
}

template <class Type, template <Type...> class AdditiveOperator, template <Type...> class MultiplicativeOperator, Type ... Values1>
	template <Type ... Values2>
inline constexpr crap :: innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> ::
	with <Values2...> :: operator typename
#if (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
crap :: innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> :: template
#else
crap :: innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> ::
#endif
	with <Values2...> :: value_type () const noexcept
{
 return crap :: innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> :: with <Values2...> :: value;
};
#if (crap_lib_integral_constant_callable >= 201304L)

template <class Type, template <Type...> class AdditiveOperator, template <Type...> class MultiplicativeOperator, Type ... Values1>
	template <Type ... Values2>
inline constexpr typename
//TODO: Add version check if changed by clang.
#if defined(__clang__) || (!defined(__clang__) && defined(__GNUC__) && (__GNUC__ < 10))
	crap :: innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> :: template
#else
	crap :: innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> ::
#endif
	with <Values2...> :: value_type
crap :: innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> ::
	with <Values2...> :: operator () () const noexcept
{
 return crap :: innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> :: with <Values2...> :: value;
};
#endif
#endif

