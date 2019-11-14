#ifndef CRAP_ALGORITHM_MERGEVALUEZIPPER
#define CRAP_ALGORITHM_MERGEVALUEZIPPER

#include "mergefortype.h"
#include "../utility/valuelistfortype.h"
#include "../numeric/reducevaluesource.h"

namespace crap
{
 template <class Type, template <Type, Type> class, template <template <Type...> class> class...> struct mergeValueZipper;

 template <class Type, template <Type, Type> class Operator> struct mergeValueZipper<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class Source>
	 struct mergeValueZipper<Type, Operator, Source>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Source<Container>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class Source1, template <template <Type...> class> class Source2>
	 struct mergeValueZipper<Type, Operator, Source1, Source2>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Source2 <Source1 <mergeForType <Type, Operator> :: template type> :: template with> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, template <template <Type...> class> class ... Sources> struct mergeValueZipper
 {
  private:
  template <template <template <Type...> class> class ... SubSources> using This = mergeValueZipper<Type, Operator, SubSources...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename reduceValueSource <Type, This, Sources...> :: template type<Container>;
 };
}
#endif

