#ifndef CRAP_ALGORITHM_SETUNIONVALUEZIPPER
#define CRAP_ALGORITHM_SETUNIONVALUEZIPPER

#include "setunionfortype.h"
#include "../utility/valuelistfortype.h"
#include "../numeric/reducevaluesource.h"

namespace crap
{
 template <class Type, template <Type, Type> class, template <template <Type...> class> class...> struct setUnionValueZipper;

 template <class Type, template <Type, Type> class Operator> struct setUnionValueZipper<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class Source>
	 struct setUnionValueZipper<Type, Operator, Source>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Source<Container>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class Source1, template <template <Type...> class> class Source2>
	 struct setUnionValueZipper<Type, Operator, Source1, Source2>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Source2 <Source1 <setUnionForType <Type, Operator> :: template type> :: template with> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class ... Sources>
	 struct setUnionValueZipper
 {
  private:
  template <template <template <Type...> class> class ... SubSources> using This = setUnionValueZipper<Type, Operator, SubSources...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename reduceValueSource <Type, This, Sources...> :: template type<Container>;
 };
}
#endif

