#ifndef CRAP_ALGORITHM_SETDIFFERENCEVALUEZIPPER
#define CRAP_ALGORITHM_SETDIFFERENCEVALUEZIPPER

#include "setdifferencefortype.h"
#include "../numeric.d/accumulatevaluesource.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, template <template <Type...> class> class...>
	 struct setDifferenceValueZipper;

 template <class Type, template <Type, Type> class Operator> struct setDifferenceValueZipper<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class Source>
	 struct setDifferenceValueZipper<Type, Operator, Source>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Source<Container>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class Source1,
	  template <template <Type...> class> class Source2>
	 struct setDifferenceValueZipper<Type, Operator, Source1, Source2>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Source2 <
	  Source1 <setDifferenceForType <Type, Operator> :: template type> :: template with
	  > :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class ... Sources>
	 struct setDifferenceValueZipper
 {
  private:
  template <template <template <Type...> class> class ... SubSources>
	  using This = setDifferenceValueZipper<Type, Operator, SubSources...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename accumulateValueSource <Type, This, Sources...> :: template type<Container>;
 };
}
#endif

