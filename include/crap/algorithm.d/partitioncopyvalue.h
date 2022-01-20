#ifndef CRAP_ALGORITHM_PARTITIONCOPYVALUE
#define CRAP_ALGORITHM_PARTITIONCOPYVALUE

#include "../utility.d/concatenatefortype.h"
#include "../utility.d/valuelistfortype.h"
#include "../utility.d/valuemultiplexer.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct partitionCopyValue;

 template <class Type, template <Type> class Operator> struct partitionCopyValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using resultTrue = Container<>;
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using resultFalse = Container<>;
 };

 template <class Type, template <Type> class Operator, Type Value>
 struct partitionCopyValue<Type, Operator, Value>
 {
  private:
  constexpr const static bool condition = (Operator <Value> :: value);
  template <template <Type...> class Container> using SourceWithout = Container<>;
  template <template <Type...> class Container> using SourceWith = Container<Value>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using resultTrue = typename valueMultiplexer <Type, condition, Container, SourceWith, SourceWithout> :: type;
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using resultFalse = typename valueMultiplexer <Type, condition, Container, SourceWithout, SourceWith> :: type;
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct partitionCopyValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <Type ... SubValues> using This = partitionCopyValue<Type, Operator, SubValues...>;
  template <template <Type...> class Container> using lowerTrue = typename values :: template till <half, This> :: template resultTrue<Container>;
  template <template <Type...> class Container> using upperTrue = typename values :: template since <half, This> :: template resultTrue<Container>;
  template <template <Type...> class Container> using lowerFalse = typename values :: template till <half, This> :: template resultFalse<Container>;
  template <template <Type...> class Container> using upperFalse = typename values :: template since <half, This> :: template resultFalse<Container>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using resultTrue = typename upperTrue <lowerTrue <concatenateForType <Type> :: template values> :: template with> :: template type<Container>;
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using resultFalse = typename upperFalse <lowerFalse <concatenateForType <Type> :: template values> :: template with> :: template type<Container>;
 };
}
#endif

