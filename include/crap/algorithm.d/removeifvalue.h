#ifndef CRAP_ALGORITHM_REMOVEIFVALUE
#define CRAP_ALGORITHM_REMOVEIFVALUE

#include "../utility.d/concatenatefortype.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct removeIfValue;

 template <class Type, template <Type> class Operator> struct removeIfValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
 };

 template <class Type, template <Type> class Operator, Type Value> struct removeIfValue<Type, Operator, Value>
 {
  private:
  using values = valueList<Type, Value>;
  constexpr const static std :: size_t offset = (Operator <Value> :: value ? 0u : 1u);
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename values :: template till<offset, Container>;
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct removeIfValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <Type ... SubValues> using This = removeIfValue<Type, Operator, SubValues...>;
  using lower = typename values :: template till <half, This> :: template type<concatenateForType <Type> :: template values>;
  using upper = typename values :: template since <half, This> :: template type<lower :: template with>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename upper :: template type<Container>;
 };
}
#endif

