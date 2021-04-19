#ifndef CRAP_ALGORITHM_SETINTERSECTIONTYPE
#define CRAP_ALGORITHM_SETINTERSECTIONTYPE

#include "equalrangetype.h"
#include "../utility/concatenatetype.h"
#include "../utility/nulltype.h"
#include "../utility/typelist.h"
#include "../utility/typemultiplexer.h"

namespace crap
{
 template <template <class, class> class, class...> struct setIntersectionType;

 template <template <class, class> class Operator> struct setIntersectionType<Operator>
 {
  template <class...> using with = nullType<>;
 };

 template <template <class, class> class Operator, class Type1> struct setIntersectionType<Operator, Type1>
 {
  template <class...> struct with;
  template <class Type2> struct with<Type2>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class, class> class Operator, class ... Types1> struct setIntersectionType
 {
  template <class...> struct with;
  template <class Type2> struct with<Type2>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class, class> class Operator, class Type1> template <class...>
	 struct setIntersectionType <Operator, Type1> :: with
 {
  template <template <class...> class Container = typeList> using type = Container<>;
 };

 template <template <class, class> class Operator, class Type1> template <class Type2>
	 struct setIntersectionType <Operator, Type1> :: template with<Type2>
 {
  private:
  template <template <class...> class Container> using ifEqual = Container<Type1>;
  template <template <class...> class Container> using ifNot = Container<>;
  template <template <class...> class Container>
	  using check = typename typeMultiplexer <Operator <Type1, Type2> :: value, Container, ifNot, ifEqual> :: type;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <Operator <Type2, Type1> :: value, Container, ifNot, check> :: type;
 };

 template <template <class, class> class Operator, class Type1> template <class First, class ... Rest>
	 struct setIntersectionType <Operator, Type1> :: template with<First, Rest...>
 {
  private:
  using range = equalRangeType<Type1, Operator, First, Rest...>;
  template <template <class...> class Container> using ifIs = Container<Type1>;
  template <template <class...> class Container> using ifNot = Container<>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <range :: begin != range :: end, Container, ifIs, ifNot> :: type;
 };

 template <template <class, class> class Operator, class ... Types1> template <class...>
	 struct setIntersectionType <Operator, Types1...> :: with
 {
  template <template <class...> class Container = typeList> using type = Container<>;
 };

 template <template <class, class> class Operator, class ... Types1> template <class Type2>
	 struct setIntersectionType <Operator, Types1...> :: template with<Type2>
 {
  private:
  using range = equalRangeType<Type2, Operator, Types1...>;
  template <template <class...> class Container>
	  using ifIs = Container<typename typeList <Types1...> :: template at<range :: begin> >;
  template <template <class...> class Container> using ifNot = Container<>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <range :: begin != range :: end, Container, ifIs, ifNot> :: type;
 };

 template <template <class, class> class Operator, class ... Types1> template <class First, class ... Rest>
	 struct setIntersectionType <Operator, Types1...> :: template with<First, Rest...>
 {
  private:
  template <class ... SubTypes> using This = setIntersectionType<Operator, SubTypes...>;
  using types1 = typeList<Types1...>;
  using types2 = typeList<First, Rest...>;
  using midType = typename types1 :: template at<(types1 :: size) / 2u>;
  using range1 = equalRangeType<midType, Operator, Types1...>;
  using range2 = equalRangeType<midType, Operator, First, Rest...>;
  constexpr const static std :: size_t range1Size = (range1 :: end) - (range1 :: begin);
  constexpr const static std :: size_t range2Size = (range2 :: end) - (range2 :: begin);
  constexpr const static std :: size_t mid1End =
	  (range1Size < range2Size) ? (range1 :: end) : ((range1 :: begin) + range2Size);
  template <template <class...> class Container>
	  using lower = typename types2 :: template
	  till <range2 :: begin, types1 :: template till<range1 :: begin, This> :: template with> :: template
	  type<Container>;
  template <template <class...> class Container>
	  using upper = typename types2 :: template
	  since <range2 :: end, types1 :: template since<range1 :: end, This> :: template with> :: template
	  type<Container>;
  template <template <class...> class Container>
	  using mid = typename types1 :: template subRange<(range1 :: begin), mid1End, Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <mid <lower <concatenateType> :: template with> :: template with> :: template
	  type<Container>;
 };
}
#endif

