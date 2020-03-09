#ifndef CRAP_NUMERIC_REDUCETYPESOURCE
#define CRAP_NUMERIC_REDUCETYPESOURCE

#include "../utility/typesourcelist.h"
#include "../utility/typelist.h"

namespace crap
{
 template <template <template <template <class...> class> class...> class, template <template <class...> class> class...>
	 struct reduceTypeSource;

 template <template <template <template <class...> class> class...> class Operator>
	 struct reduceTypeSource<Operator>
 {
  template <template <class...> class Container = typeList>
	  using type = typename Operator <> :: template type<Container>;
 };

 template <template <template <template <class...> class> class...> class Operator, template <template <class...> class> class Source>
	 struct reduceTypeSource<Operator, Source>
 {
  template <template <class...> class Container = typeList>
	  using type = typename Operator <Source> :: template type<Container>;
 };

 template <template <template <template <class...> class> class...> class Operator, template <template <class...> class> class ... Sources>
	 struct reduceTypeSource
 {
  private:
  using sources = typeSourceList<Sources...>;
  constexpr const static std :: size_t half = (sources :: size) / 2u;
  template <template <template <class...> class> class ... SubSources>
	  using This = reduceTypeSource<Operator, SubSources...>;
  template <template <class...> class Container>
	  using lower = typename sources :: template till <half, This> :: template type<Container>;
  template <template <class...> class Container>
	  using upper = typename sources :: template since <half, This> :: template type<Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Operator <lower, upper> :: template type<Container>;
 };
}
#endif

