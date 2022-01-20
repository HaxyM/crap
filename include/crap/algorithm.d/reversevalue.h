#ifndef CRAP_ALGORITHM_REVERSEVALUE
#define CRAP_ALGORITHM_REVERSEVALUE

#include "../utility.d/concatenatevalue.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, Type...> struct reverseValue;

 template <class Type> struct reverseValue<Type>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
 };

 template <class Type, Type Value> struct reverseValue<Type, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Value>;
 };

 template <class Type, Type Value1, Type Value2> struct reverseValue<Type, Value1, Value2>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Value2, Value1>;
 };

 template <class Type, Type Value1, Type Value2, Type Value3> struct reverseValue<Type, Value1, Value2, Value3>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Value3, Value2, Value1>;
 };

 template <class Type, Type ... Values> struct reverseValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static auto half = (values :: size) / 2u;
  template <Type ... SubTypes> using This = reverseValue<Type, SubTypes...>;
  template <Type ... SubTypes> using merger = concatenateValue<Type, SubTypes...>;
  using upper = typename values :: template since <half, This> :: template type<merger>;
  using lower = typename values :: template till <half, This> :: template type<upper :: template with>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = typename lower :: template type<Container>;
 };
}
#endif

