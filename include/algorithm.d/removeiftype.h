#ifndef CRAP_ALGORITHM_REMOVEIFTYPE
#define CRAP_ALGORITHM_REMOVEIFTYPE

#include "copytype.h"
#include "../utility.d/bisecttype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typelist.h"
#include "../utility.d/typemultiplexer.h"

namespace crap
{
 template <template <class> class, class...> struct removeIfType;

 template <template <class> class Operator> struct removeIfType<Operator>
	 : copyType<> {};

 template <template <class> class Operator, class Type> struct removeIfType<Operator, Type>
 {
  private:
  template <template <class...> class Container> using ifTrue = Container<>;
  template <template <class...> class Container> using ifFalse = Container<Type>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <Operator <Type> :: value, Container, ifTrue, ifFalse> :: type;
 };

 template <template <class> class Operator, class ... Types> struct removeIfType
 {
  private:
  using values = bisectType<Types...>;
  template <class ... SubTypes> using This = removeIfType<Operator, SubTypes...>;
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

