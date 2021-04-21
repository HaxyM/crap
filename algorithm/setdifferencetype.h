#ifndef CRAP_ALGORITHM_SETDIFFERENCETYPE
#define CRAP_ALGORITHM_SETDIFFERENCETYPE

#include "binarysearchtype.h"
#include "equalrangetype.h"
#include "../utility/concatenatetype.h"
#include "../utility/typelist.h"
#include "../utility/typemultiplexer.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct setDifferenceType;

 template <template <class, class> class Operator> struct setDifferenceType<Operator>
 {
  template <class...> struct with;
 };

 template <template <class, class> class Operator, class Type1> struct setDifferenceType<Operator, Type1>
 {
  template <class...> struct with;
  template <class Type2> struct with<Type2>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class, class> class Operator, class ... Types1> struct setDifferenceType
 {
  template <class...> struct with;
  template <class Type2> struct with<Type2>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class,  class> class Operator> template <class...>
	 struct setDifferenceType <Operator> :: with
 {
  template <template <class...> class Container = typeList> using type = Container<>;
 };

 template <template <class, class> class Operator, class Type1> template <class...>
	 struct setDifferenceType <Operator, Type1> :: with
 {
  template <template <class...> class Container = typeList> using type = Container<Type1>;
 };

 template <template <class, class> class Operator, class Type1> template <class Type2>
	 struct setDifferenceType <Operator, Type1> :: template with<Type2>
 {
  private:
  template <template <class...> class Container> using ifEqual = Container<>;
  template <template <class...> class Container> using ifNot = Container<Type1>;
  constexpr const static bool notEqual = (Operator <Type1, Type2> :: value) || (Operator <Type2, Type1> :: value);
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <notEqual, Container, ifNot, ifEqual> :: type;
 };

 template <template <class, class> class Operator, class Type1> template <class First, class ... Rest>
	 struct setDifferenceType <Operator, Type1> :: template with<First, Rest...>
 {
  private:
  template <template <class...> class Container> using ifHas = Container<>;
  template <template <class...> class Container> using ifNot = Container<Type1>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <
	  binarySearchType <Type1, Operator, First, Rest...> :: value,
		Container, ifHas, ifNot> :: type;
 };

 template <template <class, class> class Operator, class ... Types1> template <class...>
	 struct setDifferenceType <Operator, Types1...> :: with
 {
  template <template <class...> class Container = typeList> using type = Container<Types1...>;
 };

 template <template <class, class> class Operator, class ... Types1> template <class Type2>
	 struct setDifferenceType <Operator, Types1...> :: template with<Type2>
 {
  private:
  using range = equalRangeType<Type2, Operator, Types1...>;
  constexpr const static std :: size_t upperStart =
	  ((range :: begin == range :: end) ? (range :: begin) : (range :: begin + 1u));
  constexpr const static std :: size_t start = ((upperStart < sizeof...(Types1)) ? upperStart : sizeof...(Types1));
  template <template <class...> class Container>
	  using lower = typename typeList <Types1...> :: template till<range :: begin, Container>;
  template <template <class...> class Container>
	  using upper = typename typeList <Types1...> :: template since<start, Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <lower <concatenateType> :: template with> :: template type<Container>;
 };

 template <template <class, class> class Operator, class ... Types1> template <class First, class ... Rest>
	 struct setDifferenceType <Operator, Types1...> :: template with<First, Rest...>
 {
  private:
  template <class ... SubTypes> using This = setDifferenceType<Operator, SubTypes...>;
  using types1 = typeList<Types1...>;
  using types2 = typeList<First, Rest...>;
  using  midValue = typename types1 :: template at<(types1 :: size) / 2u>;
  using range1 = equalRangeType<midValue, Operator, Types1...>;
  using range2 = equalRangeType<midValue, Operator, First, Rest...>;
  constexpr const static std :: size_t range1Size = (range1 :: end) - (range1 :: begin);
  constexpr const static std :: size_t range2Size = (range2 :: end) - (range2 :: begin);
  constexpr const static std :: size_t mid1Begin =
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
	  using mid = typename types1 :: template subRange<mid1Begin, (range1 :: end), Container>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <mid <lower <concatenateType> :: template with> :: template with> :: template
	  type<Container>;
 };
}
#endif

