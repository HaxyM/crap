#ifndef CRAP_NUMERIC_REDUCEVALUESOURCE
#define CRAP_NUMERIC_REDUCEVALUESOURCE

#include "../utility/valuesourcelist.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, template <template <template <Type...> class> class...> class, template <template <Type...> class> class...>
	 struct reduceValueSource;

 template <class Type, template <template <template <Type...> class> class...> class Operator>
	 struct reduceValueSource<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Operator <> :: template type<Container>;
 };

 template <class Type, template <template <template <Type...> class> class...> class Operator, template <template <Type...> class> class Source>
	 struct reduceValueSource<Type, Operator, Source>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Operator <Source> :: template type<Container>;
 };

 template <class Type, template <template <template <Type...> class> class...> class Operator, template <template <Type...> class> class ... Sources>
	 struct reduceValueSource
 {
  private:
  using sources = valueSourceList<Type, Sources...>;
  constexpr const static std :: size_t half = (sources :: size) / 2u;
  template <template <template <Type...> class> class ... SubSources>
	  using This = reduceValueSource<Type, Operator, SubSources...>;
  template <template <Type...> class Container>
	  using lower = typename sources :: template till <half, This> :: template type<Container>;
  template <template <Type...> class Container>
	  using upper = typename sources :: template since <half, This> :: template type<Container>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Operator <lower, upper> :: template type<Container>;
 };
}
#endif

