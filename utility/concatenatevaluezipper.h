#ifndef CRAP_UTILITY_CONCATENATEVALUEZIPPER
#define CRAP_UTILITY_CONCATENATEVALUEZIPPER

#include "concatenatefortype.h"
#include "valuelistfortype.h"
#include "../numeric/reducevaluesource.h"

namespace crap
{
 template <class Type, template <template <Type...> class> class...> struct concatenateValueZipper;

 template <class Type> struct concatenateValueZipper<Type>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <template <Type...> class> class Source> struct concatenateValueZipper<Type, Source>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Source<Container>;
 };

 template <class Type, template <template <Type...> class> class Source1, template <template <Type...> class> class Source2>
	 struct concatenateValueZipper<Type, Source1, Source2>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Source2 <Source1 <concatenateForType <Type> :: template type> :: template with> :: template type<Container>;
 };

 template <class Type, template <template <Type...> class> class ... Sources> struct concatenateValueZipper
 {
  private:
  template <template <template <Type...> class> class ... SubSources> using This = concatenateValueZipper<Type, SubSources...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename reduceValueSource <Type, This, Sources...> :: template type<Container>;
 };
}
#endif

