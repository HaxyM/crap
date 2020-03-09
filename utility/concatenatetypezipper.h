#ifndef CRAP_UTILITY_CONCATENATETYPEZIPPER
#define CRAP_UTILITY_CONCATENATETYPEZIPPER

#include "concatenatetype.h"
#include "typelist.h"
#include "../numeric/reducetypesource.h"

namespace crap
{
 template <template <template <class...> class> class...> struct concatenateTypeZipper;

 template <> struct concatenateTypeZipper<>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <template <template <class...> class> class Source> struct concatenateTypeZipper<Source>
 {
  template <template <class...> class Container = typeList>
	  using type = Source<Container>;
 };

 template <template <template <class...> class> class Source1, template <template <class...> class> class Source2>
	 struct concatenateTypeZipper<Source1, Source2>
 {
  template <template <class...> class Container = typeList>
	  using type = typename Source2 <Source1 <concatenateType> :: template with> :: template type<Container>;
 };

 template <template <template <class...> class> class ... Sources> struct concatenateTypeZipper
 {
  private:
  template <template <template <class...> class> class ... SubSources> using This = concatenateTypeZipper<SubSources...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename reduceTypeSource <This, Sources...> :: template type<Container>;
 };
}
#endif

