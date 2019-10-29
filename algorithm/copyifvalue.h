#ifndef CRAP_ALGORITHM_COPYIFVALUE
#define CRAP_ALGORITHM_COPYIFVALUE

#include "../utility/concatenatefortype.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct copyIfValue;

 template <class Type, template <Type> class Operator> struct copyIfValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
 };

 template <class Type, template <Type> class Operator, Type Value> struct copyIfValue<Type, Operator, Value>
 {
  private:
  using values = valueList<Type, Value>;
  constexpr const static std :: size_t offset = (Operator <Value> :: value ? 0u : 1u);
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename values :: template since<offset, Container>;
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct copyIfValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <Type ... SubValues> using This = copyIfValue<Type, Operator, SubValues...>;
  using lower = typename values :: template till <half, This> :: template type<concatenateForType <Type> :: template values>;
  using upper = typename values :: template since <half, This> :: template type<lower :: template with>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename upper :: template type<Container>;
 };
}
#endif

