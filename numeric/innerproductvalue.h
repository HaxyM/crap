#ifndef CRAP_NUMERIC_INNERPRODUCTVALUE
#define CRAP_NUMERIC_INNERPRODUCTVALUE

#include "reducevalue.h"
#include "../algorithm/transform2value.h"

namespace crap
{
 template <class Type, template <Type, Type> class AdditiveOperator, template <Type, Type> class MultiplicativeOperator, Type ... Values1>
 struct innerProductValue
 {
  template <Type ... Values2> struct with;
  template <Type ... Values2> constexpr const static Type value = with <Values2...> :: value;
 };

 template <class Type, template <Type, Type> class AdditiveOperator, template <Type, Type> class MultiplicativeOperator, Type ... Values1>
 template <Type ... Values2> struct innerProductValue <Type, AdditiveOperator, MultiplicativeOperator, Values1...> :: with
 {
  private:
  template <Type ... SubTypes> using Reductor = reduceValue<Type, AdditiveOperator, SubTypes...>;
  using reduced = typename transform2Value <Type, MultiplicativeOperator, Values1...> :: template with <Values2...> :: template type<Reductor>;
  public:
  constexpr const static Type value = reduced :: value;
 };
}
#endif

