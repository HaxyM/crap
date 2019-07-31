#ifndef CRAP_ALGORITHM_COPYIFVALUE
#define CRAP_ALGORITHM_COPYIFVALUE

#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct copyIfValue;

 template <class Type, template <Type> class Operator> struct copyIfValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
 };

 template <class Type, template <Type...> class Operator, Type Value> struct copyIfValue<Type, Operator, Value>
 {
  private:
  using values = valueList<Type, Value>;
  constexpr const static std :: size_t offset = (Operator <Value> :: value ? 0u : 1u);
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = typename values :: template since<offset, Container>;
 };

 template <class Type, template <Type...> class Operator, Type ... Values> struct copyIfValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <Type ... SubValues> using This = copyIfValue<Type, Operator, SubValues...>;
  using lower = typename values :: template till<half, This> :: template type<>;
  using upper = typename values :: template since<half, This> :: template type<>;
  template <template <Type...> class Container> struct merger;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = decltype(merger <Container> :: merge(lower{}, upper{}));
 };

 template <class Type, template <Type...> class Operator, Type ... Values> template <template <Type...> class Container> struct copyIfValue <Type, Operator, Values...> :: merger
 {
  template <Type ... LowerValues, Type ... UpperValues> static Container<LowerValues..., UpperValues...> merge(valueList<Type, LowerValues...>, valueList<Type, UpperValues...>);
 };
}
#endif

