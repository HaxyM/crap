#ifndef CRAP_ALGORITHM_SETINTERSECTIONTYPEZIPPER
#define CRAP_ALGORITHM_SETINTERSECTIONTYPEZIPPER

#include "setintersectiontype.h"
#include "../numeric.d/reducetypesource.h"
#include "../utility.d/typelist.h"

namespace crap
{
 template <template <class, class> class, template <template <class...> class> class...> struct setIntersectionTypeZipper;

 template <template <class, class> class Operator> struct setIntersectionTypeZipper<Operator>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <template <class, class> class Operator, template <template <class...> class> class Source>
	 struct setIntersectionTypeZipper<Operator, Source>
 {
  template <template <class...> class Container = typeList>
	  using type = Source<Container>;
 };

 template <template <class, class> class Operator, template <template <class...> class> class Source1, template <template <class...> class> class Source2>
	 struct setIntersectionTypeZipper<Operator, Source1, Source2>
 {
  private:
  template <class ... Types> using setIntersection = setIntersectionType<Operator, Types...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Source2 <Source1 <setIntersection> :: template with> :: template type<Container>;
 };

 template <template <class, class> class Operator, template <template <class...> class> class ... Sources>
	 struct setIntersectionTypeZipper
 {
  private:
  template <template <template <class...> class> class ... SubSources>
	  using This = setIntersectionTypeZipper<Operator, SubSources...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename reduceTypeSource <This, Sources...> :: template type<Container>;
 };
}
#endif

