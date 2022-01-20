#ifndef CRAP_ALGORITHM_SETUNIONTYPE
#define CRAP_ALGORITHM_SETUNIONTYPE

#include "copytype.h"
#include "equalrangetype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typelist.h"
#include "../utility.d/typemultiplexer.h"

namespace crap
{
 template <template <class, class> class, class...>
	 struct setUnionType;

 template <template <class, class> class Operator>
	 struct setUnionType<Operator>
 {
  template <class ... Types2> using with = copyType<Types2...>;
 };

 template <template <class, class> class Operator, class Type1>
	 struct setUnionType<Operator, Type1>
 {
  template <class...> struct with;
  template <class Only> struct with<Only>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class, class> class Operator, class ... Types1>
	 struct setUnionType
 {
  template <class...> struct with;
  template <class Only> struct with<Only>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class, class> class Operator, class Type1>
	 template <class...>
	 struct setUnionType <Operator, Type1> :: with
 {
  template <template <class...> class Container = typeList> using type = Container<Type1>;
 };

 template <template<class, class> class Operator, class Type1>
	 template <class Only>
	 struct setUnionType <Operator, Type1> :: template with<Only>
 {
  private:
  template <template <class...> class Container> using ifLess = Container<Type1, Only>;
  template <template <class...> class Container> using ifEqual = Container<Type1>;
  template <template <class...> class Container> using ifGreater = Container<Only, Type1>;
  template <template <class...> class Container>
	  using lessCheck = typename typeMultiplexer <Operator <Type1, Only> :: value, Container, ifLess, ifEqual> :: type;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <Operator <Only, Type1> :: value, Container, ifGreater, lessCheck> :: type;
 };

 template <template <class, class> class Operator, class Type1>
	 template <class First, class ... Rest>
	 struct setUnionType <Operator, Type1> :: template with<First, Rest...>
 {
  private:
  using types2 = typeList<First, Rest...>;
  using range = equalRangeType<Type1, Operator, First, Rest...>;
  constexpr const static std :: size_t newBegin = (((range :: begin) == (range :: end)) ? (range :: begin) : ((range :: begin) + 1u));
  template <template <class...> class Container>
	  using middle = Container<Type1>;
  template <template <class...> class Container>
	  using lower = typename types2 :: template till<(range :: begin), Container>;
  template <template <class...> class Container>
	  using upper = typename types2 :: template since<newBegin, Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <middle <lower <concatenateType> :: template with> :: template with> :: template type<Container>;
 };

 template <template <class, class> class Operator, class ... Types1>
	 template <class...>
	 struct setUnionType <Operator, Types1...> :: with
 {
  template <template <class...> class Container = typeList> using type = Container<Types1...>;
 };

 template <template <class, class> class Operator, class ... Types1>
	 template <class Only>
	 struct setUnionType <Operator, Types1...> :: template with<Only>
 {
  private:
  using types1 = typeList<Types1...>;
  using range = equalRangeType<Only, Operator, Types1...>;
  constexpr const static bool has = ((range :: begin) != (range :: end));
  template <template <class...> class Container> using ifHas = Container<>;
  template <template <class...> class Container> using ifNot = Container<Only>;
  template <template <class...> class Container>
	  using middle = typename typeMultiplexer <has, Container, ifHas, ifNot> :: type;
  template <template <class...> class Container>
	  using lower = typename types1 :: template till<(range :: end), Container>;
  template <template <class...> class Container>
	  using upper = typename types1 :: template since<(range :: end), Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <middle <lower <concatenateType> :: template with> :: template with> :: template type<Container>;
 };

 template <template <class, class> class Operator, class ... Types1>
	 template <class First, class ... Rest>
	 struct setUnionType <Operator, Types1...> :: template with<First, Rest...>
 {
  private:
  using types1 = typeList<Types1...>;
  using types2 = typeList<First, Rest...>;
  using midType = typename types1 :: template at<(types1 :: size) / 2u>;
  using range1 = equalRangeType<midType, Operator, Types1...>;
  using range2 = equalRangeType<midType, Operator, First, Rest...>;
  constexpr const static std :: size_t range1Size = ((range1 :: end) - (range1 :: begin));
  constexpr const static std :: size_t range2NewBegin = (range2 :: begin) + range1Size;
  constexpr const static std :: size_t range2Begin =
	  ((range2NewBegin < (range2 :: end)) ? range2NewBegin : (range2 :: end));
  template <class ... SubTypes> using This = setUnionType<Operator, SubTypes...>;
  template <template <class...> class Container>
	  using middle1 = typename types1 :: template subRange<(range1 :: begin), (range1 :: end), Container>;
  template <template <class...> class Container>
	  using middle2 = typename types2 :: template subRange<range2Begin, (range2 :: end), Container>;
  template <template <class...> class Container>
	  using lower = typename types2 :: template
	  till <(range2 :: begin), types1 :: template till <(range1 :: begin), This> :: template with> :: template
	  type<Container>;
  template <template <class...> class Container>
	  using upper = typename types2 :: template
	  since <(range2 :: end), types1 :: template since <(range1 :: end), This> :: template with> :: template
	  type<Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <middle2 <middle1 <lower <concatenateType> :: template
	  with> :: template with> :: template with> :: template type<Container>;
 };
}
#endif

