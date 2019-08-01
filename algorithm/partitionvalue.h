#ifndef CRAP_ALGORITHM_PARTITIONVALUE
#define CRAP_ALGORITHM_PARTITIONVALUE

#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct partitionValue;

 template <class Type, template <Type> class Operator> struct partitionValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
  constexpr const static std :: size_t value = 0u;
 };

 template <class Type, template <Type> class Operator, Type Value> struct partitionValue<Type, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Value>;
  constexpr const static std :: size_t value = (Operator <Value> :: value ? 1u : 0u);
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct partitionValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <Type ... SubValues> using This = partitionValue<Type, Operator, SubValues...>;
  using lower = typename values :: template till<half, This>;
  using upper = typename values :: template since<half, This>;
  using lowerPassed = typename lower :: template type <> :: template till<lower :: value>;
  using upperPassed = typename upper :: template type <> :: template till<upper :: value>;
  using lowerFailed = typename lower :: template type <> :: template since<lower :: value>;
  using upperFailed = typename upper :: template type <> :: template since<upper :: value>;
  template <template <Type...> class Container> struct merger;
  template <Type ... LowerPassed, Type ... UpperPassed, Type ... LowerFailed, Type ... UpperFailed>
  static valueList<Type, LowerPassed..., UpperPassed..., LowerFailed..., UpperFailed...>
  merge(valueList<Type, LowerPassed...>, valueList<Type, UpperPassed...>, valueList<Type, LowerFailed...>, valueList<Type, UpperFailed...>);
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
  using type = decltype(merger <Container> :: merge(lowerPassed{}, upperPassed{}, lowerFailed{}, upperFailed{}));
  constexpr const static std :: size_t value = (lower :: value) + (upper :: value);
 };

 template <class Type, template <Type> class Operator, Type ... Values>
 template <template <Type...> class Container> struct partitionValue <Type, Operator, Values...> :: merger
 {
  template <Type ... LowerPassed, Type ... UpperPassed, Type ... LowerFailed, Type ... UpperFailed>
  static Container<LowerPassed..., UpperPassed..., LowerFailed..., UpperFailed...>
  merge(valueList<Type, LowerPassed...>, valueList<Type, UpperPassed...>, valueList<Type, LowerFailed...>, valueList<Type, UpperFailed...>);
 };
}
#endif

