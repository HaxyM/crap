#ifndef CRAP_ALGORITHM_SORTTYPE
#define CRAP_ALGORITHM_SORTTYPE

#include "copytype.h"
#include "partitioncopytype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typelist.h"
#include "../utility.d/typemultiplexer.h"

namespace crap
{
 template <template <class, class> class, class...> struct sortType;

 template <template <class, class> class Operator> struct sortType<Operator>
	 : copyType<> {};

 template <template <class, class> class Operator, class Type> struct sortType<Operator, Type>
	 : copyType<Type> {};

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct sortType<Operator, Type1, Type2>
 {
  private:
  template <template <class...> class Container> using sorted = Container<Type1, Type2>;
  template <template <class...> class Container> using unsorted = Container<Type2, Type1>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <!(Operator <Type1, Type2> :: value), Container, unsorted, sorted> :: type;
 };

 template <template <class, class> class Operator, class First, class ... Rest>
	 struct sortType<Operator, First, Rest...>
 {
  private:
  template <class Type> using less = Operator<Type, First>;
  template <class ... SubTypes> using This = sortType<Operator, SubTypes...>;
  using values = partitionCopyType<less, Rest...>;
  template <template <class...> class Container>
	  using lower = typename values :: template resultTrue <This> :: template type<Container>;
  template <template <class...> class Container>
	  using upper = typename values :: template resultFalse <This> :: template type<Container>;
  template <template <class...> class Container>
	  using middle = Container<First>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <middle <lower <concatenateType> :: template with> :: template with> :: template type<Container>;
 };
}
#endif

