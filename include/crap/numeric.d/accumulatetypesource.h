#ifndef CRAP_NUMERIC_ACCUMULATETYPESOURCE
#define CRAP_NUMERIC_ACCUMULATETYPESOURCE

#include "../utility.d/typelist.h"
#include "../utility.d/typesourcelist.h"

namespace crap
{
 template <template <template <template <class...> class> class...> class,
	  template <template <class...> class> class...>
	 struct accumulateTypeSource;

 template <template <template <template <class...> class> class...> class Operator>
	 struct accumulateTypeSource<Operator>
 {
  template <template <class...> class Container = typeList>
	  using type = typename Operator <> :: template type<Container>;
 };

 template <template <template <template <class...> class> class...> class Operator,
	  template <template <class...> class> class Source>
	 struct accumulateTypeSource<Operator, Source>
 {
  template <template <class...> class Container = typeList>
	  using type = typename Operator <Source> :: template type<Container>;
 };

 template <template <template <template <class...> class> class...> class Operator,
	  template <template <class...> class> class Source1, template <template <class...> class> class Source2>
	 struct accumulateTypeSource<Operator, Source1, Source2>
 {
  template <template <class...> class Container = typeList>
	  using type = typename Operator <Source1, Source2> :: template type<Container>;
 };

 template <template <template <template <class...> class> class...> class Operator,
	  template <template <class...> class> class Source1, template <template <class...> class> class Source2,
	  template <template <class...> class> class Source3>
	 struct accumulateTypeSource<Operator, Source1, Source2, Source3>
 {
  private:
  template <template <class...> class Container>
	  using subResult = typename Operator <Source1, Source2> :: template type<Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Operator <subResult, Source3> :: template type<Container>;
 };

 template <template <template <template <class...> class> class...> class Operator,
	  template <template <class...> class> class ... Sources>
	 struct accumulateTypeSource
 {
  private:
  using sources = typeSourceList<Sources...>;
  constexpr const static std :: size_t half = (sources :: size) / 2u;
  template <template <template <class...> class> class ... SubSources>
	  using lowerHalf = accumulateTypeSource<Operator, SubSources...>;
  template <template <class...> class Container>
	  using lowerHalfSource = typename sources :: template till <half, lowerHalf> :: template type<Container>;
  template <template <template <class...> class> class ... SubSources>
	  using upperHalf = accumulateTypeSource<Operator, lowerHalfSource, SubSources...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename sources :: template since <half, upperHalf> :: template type<Container>;
 };
}
#endif

