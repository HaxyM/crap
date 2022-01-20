#ifndef CRAP_ALGORITHM_COPYIFTYPE
#define CRAP_ALGORITHM_COPYIFTYPE

#include "copytype.h"
#include "../utility.d/bisecttype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typelist.h"
#include "../utility.d/typemultiplexer.h"

namespace crap
{
 template <template <class> class, class...> struct copyIfType;

 template <template <class> class Operator> struct copyIfType<Operator>
	 : copyType<> {};

 template <template <class> class Operator, class Type> struct copyIfType<Operator, Type>
 {
  private:
  template <template <class...> class Container> using ifTrue = Container<Type>;
  template <template <class...> class Container> using ifFalse = Container<>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <Operator <Type> :: value, Container, ifTrue, ifFalse> :: type;
 };

 template <template <class> class Operator, class ... Types> struct copyIfType
 {
  private:
  using values = bisectType<Types...>;
  template <class ... SubTypes> using This = copyIfType<Operator, SubTypes...>;
  template <template <class...> class Container>
	  using lower = typename values :: template lower <This> :: template type<Container>;
  template <template <class...> class Container>
	  using upper = typename values :: template upper <This> :: template type<Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <lower <concatenateType> :: template with> :: template type<Container>;
 };
}
#endif

