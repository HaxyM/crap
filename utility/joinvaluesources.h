#ifndef CRAP_UTILITY_JOINVALUESOURCES
#define CRAP_UTILITY_JOINVALUESOURCES

#include "concatenatefortype.h"
#include "valuelistfortype.h"
#include "valuesourcelist.h"

namespace crap
{
 template <class Type, template <template <Type...> class> class...> struct joinValueSources;

 template <class Type> struct joinValueSources<Type>
 {
  template <template <Type...> class Conatiner = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <template <Type...> class> class Source>
	 struct joinValueSources<Type, Source>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Source<Container>;
 };

 template <class Type, template <template <Type...> class> class Source1, template <template <Type...> class> class Source2>
	 struct joinValueSources<Type, Source1, Source2>
 {
  private:
  template <Type ... Values>
	  using first = typename Source1 <concatenateForType <Type> :: template values> :: template with<Values...>;
  public:
  template <template <Type...> class Conatiner = valueListForType <Type> :: template type>
	  using type = typename Source2 <first> :: template type<Container>;
 };

 template <class Type, template <template <Type...> class> class ... Sources> struct joinValueSources
 {
  private:
  using sources = valueSourceList<Type, Sources...>;
  constexpr const static std :: size_t half = (sources :: size) / 2u;
  template <template <template <Type...> class> class ... SubSources>
	  using This = joinValueSources<Type, SubSources...>;
  template <template <Type...> class Conatiner>
	  using lower = typename sources :: template till <half, This> :: template type<Container>;
  template <template <Type...> class Container>
	  using upper = typename sources :: template since <half, This> :: template type<Container>;
  template <Type ... Values>
	  using first = typename lower <concatenateFortType <Type> :: template values> :: template with<Values...>;
  public:
  template <template <template <Type...> class> class Container = valueListForType <Type> :: template type>
	  using type = typename upper <first> :: template type<Container>;
 };
}
#endif

