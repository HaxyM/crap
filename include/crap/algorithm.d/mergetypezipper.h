#ifndef CRAP_ALGORITHM_MERGETYPEZIPPER
#define CRAP_ALGORITHM_MERGETYPEZIPPER

#include "mergetype.h"
#include "../numeric.d/reducetypesource.h"
#include "../utility.d/typelist.h"

namespace crap
{
 template <template <class, class> class, template <template <class...> class> class...> struct mergeTypeZipper;

 template <template <class, class> class Operator> struct mergeTypeZipper<Operator>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <template <class, class> class Operator, template <template <class...> class> class Source>
	 struct mergeTypeZipper<Operator, Source>
 {
  template <template <class...> class Container = typeList>
	  using type = Source<Container>;
 };

 template <template <class, class> class Operator, template <template <class...> class> class Source1,
	  template <template <class...> class> class Source2>
	 struct mergeTypeZipper<Operator, Source1, Source2>
 {
  private:
  template <class ... Types> using mergeThis = mergeType<Operator, Types...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Source2 <Source1 <mergeThis> :: template with> :: template type<Container>;
 };

 template <template <class, class> class Operator, template <template <class...> class> class ... Sources>
	 struct mergeTypeZipper
 {
  private:
  template <template <template <class...> class> class ... SubSources>
	  using This = mergeTypeZipper<Operator, SubSources...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename reduceTypeSource <This, Sources...> :: template type<Container>;
 };
}
#endif

