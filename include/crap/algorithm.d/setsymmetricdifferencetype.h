#ifndef CRAP_ALGORITHM_SETSYMMETRICDIFFERENCETYPE
#define CRAP_ALGORITHM_SETSYMMETRICDIFFERENCETYPE

#include "copytype.h"
#include "equalrangetype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typelist.h"
#include "../utility.d/typemultiplexer.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class, class...> struct setSymmetricDifferenceType;

 template <template <class, class> class Operator> struct setSymmetricDifferenceType<Operator>
 {
  template <class ... Types2> using with = copyType<Types2...>;
 };

 template <template <class, class> class Operator, class Type1> struct setSymmetricDifferenceType<Operator, Type1>
 {
  template <class...> struct with;
  template <class Type2> struct with<Type2>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class, class> class Operator, class ... Types1> struct setSymmetricDifferenceType
 {
  template <class...> struct with;
  template <class Type2> struct with<Type2>;
  template <class First, class ... Rest> struct with<First, Rest...>;
 };

 template <template <class, class> class Operator, class Type1> template <class...>
	 struct setSymmetricDifferenceType <Operator, Type1> :: with
 {
  template <template <class...> class Container = typeList> using type = Container<Type1>;
 };

 template <template <class, class> class Operator, class Type1> template <class Type2>
	 struct setSymmetricDifferenceType <Operator, Type1> :: template with<Type2>
 {
  private:
  template <template <class...> class Container> using ifLess = Container<Type1, Type2>;
  template <template <class...> class Container> using ifGreater = Container<Type2, Type1>;
  template <template <class...> class Container> using ifEqual = Container<>;
  template <template <class...> class Container>
	  using check = typename typeMultiplexer <Operator <Type1, Type2> :: value, Container, ifLess, ifEqual> :: type;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <Operator <Type2, Type1> :: value, Container, ifGreater, check> :: type;
 };

 template <template <class, class> class Operator, class Type1> template <class First, class ... Rest>
	 struct setSymmetricDifferenceType <Operator, Type1> :: template with<First, Rest...>
 {
  private:
  using range = equalRangeType<Type1, Operator, First, Rest...>;
  template <template <class...> class Container>
	  using ifHas = typename typeList <First, Rest...> :: template
	  subRange<range :: begin + 1u, range :: end, Container>;
  template <template <class...> class Container> using ifNot = Container<Type1>;
  template <template <class...> class Container>
	  using lower = typename typeList <First, Rest...> :: template till<range :: begin, Container>;
  template <template <class...> class Container>
	  using upper = typename typeList <First, Rest...> :: template since<range :: end, Container>;
  template <template <class...> class Container>
	  using middle = typename typeMultiplexer <range :: begin != range :: end, Container, ifHas, ifNot> :: type;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <middle <lower <concatenateType> :: template with> :: template with> :: template
	  type<Container>;
 };

 template <template <class, class> class Operator, class ... Types1> template <class...>
	 struct setSymmetricDifferenceType <Operator, Types1...> :: with
 {
  template <template <class...> class Container = typeList> using type = Container<Types1...>;
 };

 template <template <class, class> class Operator, class ... Types1> template <class Type2>
	 struct setSymmetricDifferenceType <Operator, Types1...> :: template with<Type2>
 {
  private:
  using range = equalRangeType<Type2, Operator, Types1...>;
  template <template <class...> class Container>
	  using ifHas = typename typeList <Types1...> :: template
	  subRange<range :: begin + 1u, range :: end, Container>;
  template <template <class...> class Container> using ifNot = Container<Type2>;
  template <template <class...> class Container>
	  using lower = typename typeList <Types1...> :: template till<range :: begin, Container>;
  template <template <class...> class Container>
	  using upper = typename typeList <Types1...> :: template since<range :: end, Container>;
  template <template <class...> class Container>
	  using middle = typename typeMultiplexer <range :: begin != range :: end, Container, ifHas, ifNot> :: type;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename upper <middle <lower <concatenateType> :: template with> :: template with> :: template
	  type<Container>;
 };

 template <template <class, class> class Operator, class ... Types1> template <class First, class ... Rest>
	 struct setSymmetricDifferenceType <Operator, Types1...> :: template with<First, Rest...>
 {
  private:
  using types1 = typeList<Types1...>;
  using types2 = typeList<First, Rest...>;
  using midType = typename types1 :: template at<(types1 :: size) / 2u>;
  using range1 = equalRangeType<midType, Operator, Types1...>;
  using range2 = equalRangeType<midType, Operator, First, Rest...>;
  constexpr const static std :: size_t range1Size = ((range1 :: end) - (range1 :: begin));
  constexpr const static std :: size_t range2Size = ((range2 :: end) - (range2 :: begin));
  constexpr const static std :: size_t range1ShiftedBegin = ((range1 :: begin) + range2Size);
  constexpr const static std :: size_t range2ShiftedBegin = ((range2 :: begin) + range1Size);
  constexpr const static std :: size_t range1Begin =
	  ((range1ShiftedBegin < (range1 :: end)) ? range1ShiftedBegin : (range1 :: end));
  constexpr const static std :: size_t range2Begin =
	  ((range2ShiftedBegin < (range2 :: end)) ? range2ShiftedBegin : (range2 :: end));
  template <class ... SubTypes> using This = setSymmetricDifferenceType<Operator, SubTypes...>;
  template <template <class...> class Container>
	  using mid1 = typename types1 :: template subRange <range1Begin, (range1 :: end), Container>;
  template <template <class...> class Container>
	  using mid2 = typename types2 :: template subRange <range2Begin, (range2 :: end), Container>;
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
	  using type = typename upper <mid2 <mid1 <lower <concatenateType> :: template
	  with> :: template with> :: template with> :: template type<Container>;
 };
}
#endif

