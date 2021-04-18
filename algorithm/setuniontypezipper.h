#ifndef CRAP_ALGORITHM_SETUNIONTYPEZIPPER
#define CRAP_ALGORITHM_SETUNIONTYPEZIPPER

#include "setuniontype.h"
#include "../numeric/reducetypesource.h"
#include "../utility/typelist.h"

namespace crap
{
 template <template <class, class> class, template <template <class...> class> class...> struct setUnionTypeZipper;

 template <template <class, class> class Operator> struct setUnionTypeZipper<Operator>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <template <class, class> class Operator, template <template <class...> class> class Source>
	 struct setUnionTypeZipper<Operator, Source>
 {
  template <template <class...> class Container = typeList>
	  using type = Source<Container>;
 };

 template <template <class, class> class Operator, template <template <class...> class> class Source1, template <template <class...> class> class Source2>
	 struct setUnionTypeZipper<Operator, Source1, Source2>
 {
  private:
  template <class ... Types> using setUnion = setUnionType<Operator, Types...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Source2 <Source1 <setUnion> :: template with> :: template type<Container>;
 };

 template <template <class, class> class Operator, template <template <class...> class> class ... Sources>
	 struct setUnionTypeZipper
 {
  private:
  template <template <template <class...> class> class ... SubSources>
	  using This = setUnionTypeZipper<Operator, SubSources...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename reduceTypeSource <This, Sources...> :: template type<Container>;
 };
}
#endif

