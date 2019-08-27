#ifndef CRAP_ALGORITHM_ROTATEVALUE
#define CRAP_ALGORITHM_ROTATEVALUE

#include "../utility/mergevalue.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <std :: size_t N, class Type, Type...> struct rotateValue;

 template <std :: size_t N, class Type> struct rotateValue<N, Type>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
 };

 template <std :: size_t N, class Type, Type Value> struct rotateValue<N, Type, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Value>;
 };

 template <std :: size_t N, class Type, Type ... Values> struct rotateValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static auto pivot = N % (values :: size);
  template <Type ... SubTypes> using merger = mergeValue<Type, SubTypes...>;
  using upper = typename values :: template since<pivot, merger>;
  using lower = typename values :: template till<pivot, upper :: template with>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = typename lower :: template type<Container>;
 };
}
#endif

