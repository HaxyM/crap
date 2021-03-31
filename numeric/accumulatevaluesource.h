#ifndef CRAP_NUMERIC_ACCUMULATEVALUESOURCE
#define CRAP_NUMERIC_ACCUMULATEVALUESOURCE

#include "../utility/valuesourcelist.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, template <template <template <Type...> class> class...> class, template <template <Type...> class> class...>
	 struct accumulateValueSource;

 template <class Type, template <template <template <Type...> class> class...> class Operator>
	 struct accumulateValueSource<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Operator <> :: template type<Container>;
 };

 template <class Type, template <template <template <Type...> class> class...> class Operator, template <template <Type...> class> class Source>
	 struct accumulateValueSource<Type, Operator, Source>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Operator <Source> :: template type<Container>;
 };

 template <class Type, template <template <template <Type...> class> class...> class Operator,
	  template <template <Type...> class> class Source1, template <template <Type...> class> class Source2>
	 struct accumulateValueSource<Type, Operator, Source1, Source2>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Operator <Source1, Source2> :: template type<Container>;
 };

 template <class Type, template <template <template <Type...> class> class...> class Operator,
	  template <template <Type...> class> class Source1, template <template <Type...> class> class Source2,
	  template <template <Type...> class> class Source3>
	 struct accumulateValueSource<Type, Operator, Source1, Source2, Source3>
 {
  private:
  template <template <Type...> class Container>
	  using subResult = typename Operator <Source1, Source2> :: template type<Container>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Operator <subResult, Source3> :: template type<Container>;
 };

 template <class Type, template <template <template <Type...> class> class...> class Operator, template <template <Type...> class> class ... Sources>
	 struct accumulateValueSource
 {
  private:
  using sources = valueSourceList<Type, Sources...>;
  constexpr const static std :: size_t half = (sources :: size) / 2u;
  template <template <template <Type...> class> class ... SubSources>
	  using lowerHalf = accumulateValueSource<Type, Operator, SubSources...>;
  template <template <Type...> class Container>
	  using lowerHalfSource = typename sources :: template till <half, lowerHalf> :: template type<Container>;
  template <template <template <Type...> class> class ... SubSources>
	  using upperHalf = accumulateValueSource<Type, Operator, lowerHalfSource, SubSources...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename sources :: template since <half, upperHalf> :: template type<Container>;
 };
}
#endif

