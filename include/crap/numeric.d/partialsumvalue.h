#ifndef CRAP_NUMERIC_PARTIALSUMVALUE
#define CRAP_NUMERIC_PARTIALSUMVALUE

#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct partialSumValue;

 template <class Type, template <Type, Type> class Operator> struct partialSumValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value> struct partialSumValue<Type, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Value>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct partialSumValue
 {
  private:
  using values = valueList<Type, Values...>;
  template <Type ... SubValues> using This = partialSumValue<Type, Operator, SubValues...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  using lower = typename values :: template till <half, This> :: template type<>;
  using upper = typename values :: template since <half, This> :: template type<>;
  constexpr const static Type lowerLast = lower :: template At <lower :: size - 1u> :: value;
  template <template <Type...> class Container, Type LowerLast> struct merger;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
  using type = decltype(merger <Container, lowerLast> :: merge(lower{}, upper{}));
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
 template <template <Type...> class Container, Type LowerLast> struct partialSumValue <Type, Operator, Values...> :: merger
 {
  template <Type ... LowerValues, Type ... UpperValues> static Container<LowerValues..., (Operator <LowerLast, UpperValues> :: value)...>
  merge(valueList<Type, LowerValues...>, valueList<Type, UpperValues...>);
 };
}
#endif

