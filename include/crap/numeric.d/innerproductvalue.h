#ifndef CRAP_NUMERIC_INNERPRODUCTVALUE
#define CRAP_NUMERIC_INNERPRODUCTVALUE

#include "reducevalue.h"
#include "../algorithm.d/transform2value.h"
#include "../utility.d/language.h"

namespace crap
{
 template <class Type, template <Type...> class AdditiveOperator, template <Type...> class MultiplicativeOperator, Type ... Values1>
 struct innerProductValue
 {
  template <Type ... Values2> struct with;
  #if CPP14
  template <Type ... Values2> constexpr const static Type value = with <Values2...> :: value;
  #endif
 };

 template <class Type, template <Type...> class AdditiveOperator, template <Type...> class MultiplicativeOperator, Type ... Values1>
 template <Type ... Values2> struct innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> :: with
 {
  private:
  template <Type A, Type B> using multiplicative = MultiplicativeOperator<A, B>;
  template <Type ... SubTypes> using Reductor = reduceValue<Type, AdditiveOperator, SubTypes...>;
  using reduced = typename transform2Value <Type, multiplicative, Values1...> :: template with <Values2...> :: template type<Reductor>;
  public:
  constexpr const static Type value = reduced :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <Type...> class AdditiveOperator, template <Type...> class MultiplicativeOperator, Type ... Values1>  template <Type ... Values2>
inline constexpr crap :: innerProductnValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> :: template
	with <Values2...> :: operator
typename crap :: innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> :: template
	with <Values2...> :: value_type () const noexcept
{
 return crap :: innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> :: template with <Values2...> :: value;
};
#endif
