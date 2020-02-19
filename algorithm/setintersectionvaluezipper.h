#ifndef CRAP_ALGORITHM_SETINTERSECTIONVALUEZIPPER
#define CRAP_ALGORITHM_SETINTERSECTIONVALUEZIPPER

#include "setintersectionfortype.h"
#include "../utility/valuelistfortype.h"
#include "../numeric/reducevaluesource.h"

namespace crap
{
 template <class Type, template <Type, Type> class, template <template <Type...> class> class...> struct setIntersectionValueZipper;

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class Source>
	 struct setIntersectionValueZipper<Type, Operator, Source>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Source<Container>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class Source1, template <template <Type...> class> class Source2>
	 struct setIntersectionValueZipper<Type, Operator, Source1, Source2>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Source2 <Source1 <setIntersectionForType <Type, Operator> :: template type> :: template with> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class ... Sources>
	 struct setIntersectionValueZipper
 {
  private:
  static_assert(sizeof...(Sources) != 0u, "setIntersection on empty sources collection is not yet implemented.");
  template <template <template <Type...> class> class ... SubSources> using This = setIntersectionValueZipper<Type, Operator, SubSources...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename reduceValueSource <Type, This, Sources...> :: template type<Container>;
 };
}
#endif

