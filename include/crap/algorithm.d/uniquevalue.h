#ifndef CRAP_ALGORITHM_UNIQUEVALUE
#define CRAP_ALGORITHM_UNIQUEVALUE

#include "../utility.d/concatenatefortype.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct uniqueValue;
 
 template <class Type, template <Type, Type> class Operator> struct uniqueValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value> struct uniqueValue<Type, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Value>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct uniqueValue
 {
  private:
  using values = valueList<Type, Values...>;
  template <Type ... SubValues> using This = uniqueValue<Type, Operator, SubValues...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  using lower = typename values :: template till <half, This> :: template type<>;
  using upper = typename values :: template since <half, This> :: template type<>;
  constexpr const static Type lowerLast = lower :: template At <lower :: size - 1u> :: value;
  constexpr const static Type upperFirst = upper :: template At <0u> :: value;
  using merger = typename lower :: template copy<concatenateForType <Type> :: template values>;
  constexpr const static bool shouldSkipUpperFirst = Operator <lowerLast, upperFirst> :: value;
  //Upper with or without first value
  using upperToMerge = typename upper :: template since<(shouldSkipUpperFirst ? 1u : 0u), merger :: template with>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename upperToMerge :: template type<Container>;
 };
}
#endif

