#ifndef CRAP_ALGORITHM_UNIQUETYPE
#define CRAP_ALGORITHM_UNIQUETYPE

#include "copytype.h"
#include "../utility.d/bisecttype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/emptytype.h"
#include "../utility.d/typelist.h"
#include "../utility.d/typemultiplexer.h"

#include <type_traits>

namespace crap
{
 template <template <class, class> class, class...> struct uniqueType;

 template <template <class, class> class Operator> struct uniqueType<Operator>
	 : copyType<> {};

 template <template <class, class> class Operator, class Type> struct uniqueType<Operator, Type>
	 : copyType<Type>
 {
  private:
  template <template <class, class> class, class...> friend struct uniqueType;
  using first = Type;
  using last = Type;
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct uniqueType<Operator, Type1, Type2>
 {
  private:
  template <template <class...> class Container> using ifEqual = Container<Type1>;
  template <template <class...> class Container> using ifNotEqual = Container<Type1, Type2>;
  template <template <class, class> class, class...> friend struct uniqueType;
  using first = Type1;
  using last = typename std :: conditional <Operator <Type1, Type2> :: value, Type1, Type2> :: type;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <Operator <Type1, Type2> :: value, Container, ifEqual, ifNotEqual> :: type;
 };

 template <template <class, class> class Operator, class ... Types> struct uniqueType
 {
  private:
  using values = bisectType<Types...>;
  template <class ... SubTypes> using This = uniqueType<Operator, SubTypes...>;
  using lower = typename values :: template lower<This>;
  using upper = typename values :: template upper<This>;
  constexpr const static auto borderControl = Operator <typename lower :: last, typename upper :: first> :: value;
  template <class...> struct front;
  template <class First, class ... Rest> struct front<First, Rest...>;
  using upperFront = typename upper :: template type<front>;
  template <template <class...> class Container>
	  using upperFinal = typename typeMultiplexer <borderControl, Container, upperFront :: template pop, upperFront :: template pass> :: type;
  template <template<class, class> class, class...> friend struct uniqueType;
  using first = typename lower :: first;
  using last = typename std :: conditional <upperFinal <emptyType> :: value, typename lower :: last, typename upper :: last> :: type;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upperFinal <lower :: template type <concatenateType> :: template with> :: template type<Container>;
 };

 template <template <class, class> class Operator, class ... Types> template <class First, class ... Rest>
	 struct uniqueType <Operator, Types...> :: front<First, Rest...>
 {
  template <template <class...> class Container> using pop = Container<Rest...>;
  template <template <class...> class Container> using pass = Container<First, Rest...>;
 };
}
#endif

