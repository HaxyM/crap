#ifndef CRAP_ALGORITHM_MERGETYPE
#define CRAP_ALGORITHM_MERGETYPE

#include "equalrangetype.h"
#include "lowerboundtype.h"
#include "upperboundtype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/splittype.h"
#include "../utility.d/typelist.h"
#include "../utility.d/typemultiplexer.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct mergeType;

 template <template <class, class> class Operator> struct mergeType<Operator>
 {
  template <class ... Types2> struct with;
 };

 template <template <class, class> class Operator, class Type1> struct mergeType<Operator, Type1>
 {
  private:
  template <std :: size_t, class...> struct withImplementation;
  template <class ... Empty> struct withImplementation<0u, Empty...>;
  template <class Only> struct withImplementation<1u, Only>;
  public:
  template <class ... Types2> using with = withImplementation<sizeof...(Types2), Types2...>;
 };

 template <template <class, class> class Operator, class ... Types1> struct mergeType
 {
  private:
  template <std :: size_t, class...> struct withImplementation;
  template <class ... Empty> struct withImplementation<0u, Empty...>;
  template <class Only> struct withImplementation<1u, Only>;
  public:
  template <class ... Types2> using with = withImplementation<sizeof...(Types2), Types2...>;
 };

 template <template <class, class> class Operator> template <class ... Types2>
	 struct mergeType <Operator> :: with
 {
  template <template <class...> class Container = typeList>
	  using type = Container<Types2...>;
 };

 template <template <class, class> class Operator, class Type1> template <std :: size_t, class ... Types2>
	 struct mergeType <Operator, Type1> :: withImplementation
 {
  private:
  template <template <class...> class Container> using inner = Container<Type1>;
  constexpr const static auto splitPoint = lowerBoundType <Type1, Operator, Types2...> :: value;
  using values = splitType<splitPoint, Types2...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename values :: template upper <
	  inner <values :: template lower <concatenateType> :: template
	  with> :: template with> :: template type<Container>;
 };

 template <template <class, class> class Operator, class Type1> template <class ... Empty>
	 struct mergeType <Operator, Type1> :: template withImplementation<0u, Empty...>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<Type1>;
 };

 template <template <class, class> class Operator, class Type1> template <class Only>
	 struct mergeType <Operator, Type1> :: template withImplementation<1u, Only>
 {
  private:
  template <template <class...> class Container> using ifOrdered = Container<Type1, Only>;
  template <template <class...> class Container> using ifUnordered = Container<Only, Type1>;
  constexpr const static auto isOrdered = Operator <Type1, Only> :: value;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <isOrdered, Container, ifOrdered, ifUnordered> :: type;
 };

 template <template <class, class> class Operator, class ... Types1>
	 template <std :: size_t, class ... Types2>
	 struct mergeType <Operator, Types1...> :: withImplementation
 {
  private:
  using values1 = typeList<Types1...>;
  using values2 = typeList<Types2...>;
  using pivot = typename values1 :: template at<(values1 :: size) / 2u>;
  using values1Ranges = equalRangeType<pivot, Operator, Types1...>;
  using values2Ranges = equalRangeType<pivot, Operator, Types2...>;
  template <class ... SubTypes> using This = mergeType<Operator, SubTypes...>;
  template <template <class...> class Container>
	  using lower = typename values2 :: template
	  till <values2Ranges :: begin, values1 :: template
	  till <values1Ranges :: begin, This> :: template
	  with> :: template type<Container>;
  template <template <class...> class Container>
	  using inner1 = typename values1 :: template
	  subRange<values1Ranges :: begin, values1Ranges :: end, Container>;
  template <template <class...> class Container>
	  using inner2 = typename values2 :: template
	  subRange<values2Ranges :: begin, values2Ranges :: end, Container>;
  template <template <class...> class Container>
	  using upper = typename values2 :: template
	  since <values2Ranges :: end, values1 :: template
	  since <values1Ranges :: end, This> :: template
	  with> :: template type<Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <inner2 <inner1 <lower <concatenateType> :: template
	  with> :: template with> :: template with> :: template type<Container>;
 };

 template <template <class, class> class Operator, class ... Types1> template <class ... Empty>
	 struct mergeType <Operator, Types1...> :: template withImplementation<0u, Empty...>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<Types1...>;
 };

 template <template <class, class> class Operator, class ... Types1> template <class Only>
	 struct mergeType <Operator, Types1...> :: template withImplementation<1u, Only>
 {
  private:
  template <template <class...> class Container> using inner = Container<Only>;
  constexpr const static auto splitPoint = upperBoundType <Only, Operator, Types1...> :: value;
  using values = splitType<splitPoint, Types1...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename values :: template upper <
	  inner <values :: template lower <concatenateType> :: template
	  with> :: template with> :: template type<Container>;
 };
}
#endif

