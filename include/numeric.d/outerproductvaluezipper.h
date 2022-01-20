#ifndef CRAP_NUMERIC_OUTERPRODUCTVALUEZIPPER
#define CRAP_NUMERIC_OUTERPRODUCTVALUEZIPPER

#include "outerproductfortype.h"
#include "../numeric.d/reducevaluesource.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, template <template <Type...> class> class...> struct outerProductValueZipper;

 template <class Type, template <Type, Type> class Operator> struct outerProductValueZipper<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class Source>
	 struct outerProductValueZipper<Type, Operator, Source>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Source<Container>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class Source1, template <template <Type...> class> class Source2>
	 struct outerProductValueZipper<Type, Operator, Source1, Source2>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Source2 <Source1 <outerProductForType <Type, Operator> :: template type> :: template with> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class ... Sources> struct outerProductValueZipper
 {
  private:
  template <template <template <Type...> class> class ... SubSources> using This = outerProductValueZipper<Type, Operator, SubSources...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename reduceValueSource <Type, This, Sources...> :: template type<Container>;
 };
}
#endif

