#ifndef CRAP_ALGORITHM_SETDIFFERENCETYPEZIPPER
#define CRAP_ALGORITHM_SETDIFFERENCETYPEZIPPER

#include "setdifferencetype.h"
#include "../numeric/accumulatetypesource.h"
#include "../utility/typelist.h"

namespace crap
{
 template <template <class, class> class, template <template <class...> class> class...> struct setDifferenceTypeZipper;

 template <template <class, class> class Operator> struct setDifferenceTypeZipper<Operator>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <template <class, class> class Operator, template <template <class...> class> class Source>
	 struct setDifferenceTypeZipper<Operator, Source>
 {
  template <template <class...> class Container = typeList>
	  using type = Source<Container>;
 };

 template <template <class, class> class Operator, template <template <class...> class> class Source1, template <template <class...> class> class Source2>
	 struct setDifferenceTypeZipper<Operator, Source1, Source2>
 {
  private:
  template <class ... Types> using setDifference = setDifferenceType<Operator, Types...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Source2 <Source1 <setDifference> :: template with> :: template type<Container>;
 };

 template <template <class, class> class Operator, template <template <class...> class> class ... Sources>
	 struct setDifferenceTypeZipper
 {
  private:
  template <template <template <class...> class> class ... SubSources>
	  using This = setDifferenceTypeZipper<Operator, SubSources...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename accumulateTypeSource <This, Sources...> :: template type<Container>;
 };
}
#endif

