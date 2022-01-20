#ifndef CRAP_ALGORITHM_PARTITIONCOPYTYPE
#define CRAP_ALGORITHM_PARTITIONCOPYTYPE

#include "../utility.d/bisecttype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typelist.h"
#include "../utility.d/typemultiplexer.h"

namespace crap
{
 template <template <class> class, class...> struct partitionCopyType;

 template <template <class> class Operator> struct partitionCopyType<Operator>
 {
  template <template <class...> class Container = typeList>
	  using resultTrue = Container<>;
  template <template <class...> class Container = typeList>
	  using resultFalse = Container<>;
 };

 template <template <class> class Operator, class Type>
 struct partitionCopyType<Operator, Type>
 {
  private:
  template <template <class...> class Container> using Without = Container<>;
  template <template <class...> class Container> using With = Container<Type>;
  public:
  template <template <class...> class Container = typeList>
	  using resultTrue = typename typeMultiplexer <Operator <Type> :: value, Container, With, Without> :: type;
  template <template <class...> class Container = typeList>
	  using resultFalse = typename typeMultiplexer <Operator <Type> :: value, Container, Without, With> :: type;
 };

 template <template <class> class Operator, class ... Types> struct partitionCopyType
 {
  private:
  using values = bisectType<Types...>;
  template <class ... SubTypes> using This = partitionCopyType<Operator, SubTypes...>;
  template <template <class...> class Container>
	  using lowerTrue = typename values :: template lower <This> :: template resultTrue<Container>;
  template <template <class...> class Container>
	  using upperTrue = typename values :: template upper <This> :: template resultTrue<Container>;
  template <template <class...> class Container>
	  using lowerFalse = typename values :: template lower <This> :: template resultFalse<Container>;
  template <template <class...> class Container>
	  using upperFalse = typename values :: template upper <This> :: template resultFalse<Container>;
  public:
  template <template <class...> class Container = typeList>
	  using resultTrue = typename upperTrue <lowerTrue <concatenateType> :: template with> :: template type<Container>;
  template <template <class...> class Container = typeList>
	  using resultFalse = typename upperFalse <lowerFalse <concatenateType> :: template with> :: template type<Container>;
 };
}
#endif

