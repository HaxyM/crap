#ifndef CRAP_ALGORITHM_PARTIALSORTCOPYTYPE
#define CRAP_ALGORITHM_PARTIALSORTCOPYTYPE

#include <cstddef>
#include <type_traits>

#include "mintype.h"
#include "partitioncopytype.h"
#include "sorttype.h"
#include "../utility/concatenatetype.h"
#include "../utility/sizetype.h"
#include "../utility/typelist.h"

namespace crap
{
 template <std :: size_t, template <class, class> class, class...> struct partialSortCopyType;

 template <template <class, class> class Operator> struct partialSortCopyType<0u, Operator>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <std :: size_t N, template <class, class> class Operator>
	 struct partialSortCopyType<N, Operator>
 { //Always fail due to above specialisation.
  static_assert(N <= 0u, "Index out of range.");
 };

 template <template <class, class> class Operator, class Type>
	 struct partialSortCopyType<0u, Operator, Type>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <template <class, class> class Operator, class Type>
	 struct partialSortCopyType<1u, Operator, Type>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<Type>;
 };

 template <std :: size_t N, template <class, class> class Operator, class Type>
	 struct partialSortCopyType<N, Operator, Type>
 { //Always fail due to two above specialisations.
  static_assert(N <= 1u, "Index out of range.");
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct partialSortCopyType<0u, Operator, Type1, Type2>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct partialSortCopyType<1u, Operator, Type1, Type2>
 {
  private:
  template <template <class...> class Container> struct Implementation;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Implementation <Container> :: type;
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 struct partialSortCopyType<2u, Operator, Type1, Type2>
 {
  private:
  template <template <class...> class Container> struct Implementation;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Implementation <Container> :: type;
 };

 template <std :: size_t N, template <class, class> class Operator, class Type1, class Type2>
	 struct partialSortCopyType<N, Operator, Type1, Type2>
 { //Always fail due to three above specialisations.
  static_assert(N <= 2u, "Index out of range.");
 };

 template <template <class, class> class Operator, class ... Types>
	 struct partialSortCopyType<0u, Operator, Types...>
 {
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <template <class, class> class Operator, class ... Types>
	 struct partialSortCopyType<1u, Operator, Types...>
 {
  private:
  template <template <class...> class Container> struct Implementation;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Implementation <Container> :: type;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 struct partialSortCopyType
 {
  private:
  static_assert(N <= sizeof...(Types), "Index out of range.");
  template <template <class...> class Container, std :: size_t NewN, std :: size_t Elements, class ... SubTypes>
	  struct Implementation;
  template <template <class...> class Container>
	  struct Implementation<Container, 0u, 0u>;
  template <template <class...> class Container, class SubType>
	  struct Implementation<Container, 0u, 1u, SubType>;
  template <template <class...> class Container, class SubType>
	  struct Implementation<Container, 1u, 1u, SubType>;
  template <template <class...> class Container, class SubType1, class SubType2>
	  struct Implementation<Container, 0u, 2u, SubType1, SubType2>;
  template <template <class...> class Container, class SubType1, class SubType2>
	  struct Implementation<Container, 1u, 2u, SubType1, SubType2>;
  template <template <class...> class Container, class SubType1, class SubType2>
	  struct Implementation<Container, 2u, 2u, SubType1, SubType2>;
  template <template <class...> class Container, std :: size_t Elements, class ... SubTypes>
	  struct Implementation<Container, 0u, Elements, SubTypes...>;
  template <template <class...> class Container, std :: size_t Elements, class ... SubTypes>
	  struct Implementation<Container, 1u, Elements, SubTypes...>;
  template <template <class...> class Container, std :: size_t Elements, class ... SubTypes>
	  struct Implementation<Container, Elements, Elements, SubTypes...>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Implementation <Container, N, sizeof...(Types), Types...> :: type;
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 template <template <class...> class Container>
 struct partialSortCopyType <1u, Operator, Type1, Type2> :: Implementation
 {
  using type = Container<typename std :: conditional<Operator <Type2, Type1> :: value, Type2, Type1> :: type>;
 };

 template <template <class, class> class Operator, class Type1, class Type2>
	 template <template <class...> class Container>
 struct partialSortCopyType <2u, Operator, Type1, Type2> :: Implementation
 {
  using type = Container<
	typename std :: conditional <Operator <Type2, Type1> :: value, Type2, Type1> :: type,
	typename std :: conditional <Operator <Type2, Type1> :: value, Type1, Type2> :: type>;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container>
 struct partialSortCopyType <1u, Operator, Types...> :: Implementation
 {
  using type = Container<typename minType <Operator, Types...> :: type>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, std :: size_t NewN, std :: size_t Elements, class ... SubTypes>
 struct partialSortCopyType <N, Operator, Types...> :: Implementation
 {
  private:
  using types = typeList<SubTypes...>;
  using pivot = typename types :: template at<NewN>;
  template <class Type> using lowerCompare = Operator<pivot, Type>;
  template <class Type> using upperCompare = Operator<Type, pivot>;
  template <class ... SubSubTypes> using lowerPartitioner = partitionCopyType<lowerCompare, SubSubTypes...>;
  template <class ... SubSubTypes> using upperPartitioner = partitionCopyType<upperCompare, SubSubTypes...>;
  using lowerPartitioned = typename types :: template till<N, lowerPartitioner>;
  using upperPartitioned = typename types :: template since<N + 1u, upperPartitioner>;
  using lowerFailed = typename lowerPartitioned :: template resultTrue<concatenateType>;
  using upperFailed = typename upperPartitioned :: template resultTrue<concatenateType>;
  template <template <class...> class SubContainer>
	  using lowerFinal = typename lowerPartitioned :: template
	  resultFalse<upperFailed :: template with> :: template type<SubContainer>;
  template <template <class...> class SubContainer>
	  using upperFinal = typename upperPartitioned :: template
	  resultFalse<lowerFailed :: template with> :: template type<SubContainer>;
  constexpr const static std :: size_t lowerSize = lowerFinal <sizeType> :: value;
  template <class ... SubSubTypes>
	  using lowerPartialSorter = Implementation<concatenateType,
		((NewN < lowerSize) ? NewN : lowerSize), sizeof...(SubSubTypes), SubSubTypes...>;
  using lower = typename lowerFinal<lowerPartialSorter> :: type;
  using middle = typename
	  std :: conditional<(NewN > lowerSize), typename lower :: template with<pivot>, lower> :: type;
  template <class ... SubSubTypes>
	  using upperPartialSorter = Implementation<middle :: template with,
		((NewN > lowerSize) ? (NewN - (lowerSize + 1u)) : 0u), sizeof...(SubSubTypes), SubSubTypes...>;
  public:
  using type = typename upperFinal<upperPartialSorter> :: type :: template type<Container>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container>
 struct partialSortCopyType <N, Operator, Types...> :: template
	 Implementation<Container, 0u, 0u>
 {
  using type = Container<>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, class SubType>
 struct partialSortCopyType <N, Operator, Types...> :: template
	 Implementation<Container, 0u, 1u, SubType>
 {
  using type = Container<>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, class SubType>
 struct partialSortCopyType <N, Operator, Types...> :: template
	 Implementation<Container, 1u, 1u, SubType>
 {
  using type = Container<SubType>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, class SubType1, class SubType2>
 struct partialSortCopyType <N, Operator, Types...> :: template
	 Implementation<Container, 0u, 2u, SubType1, SubType2>
 {
  using type = Container<>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, class SubType1, class SubType2>
 struct partialSortCopyType <N, Operator, Types...> :: template
	 Implementation<Container, 1u, 2u, SubType1, SubType2>
 {
  using type = Container<
	  typename std :: conditional <Operator <SubType2, SubType1> :: value, SubType2, SubType1> :: type>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, class SubType1, class SubType2>
 struct partialSortCopyType <N, Operator, Types...> :: template
	 Implementation<Container, 2u, 2u, SubType1, SubType2>
 {
  using type = Container<
	  typename std :: conditional <Operator <SubType2, SubType1> :: value, SubType2, SubType1> :: type,
	  typename std :: conditional <Operator <SubType2, SubType1> :: value, SubType1, SubType2> :: type>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, std :: size_t Elements, class ... SubTypes>
 struct partialSortCopyType <N, Operator, Types...> :: template
	 Implementation<Container, 0u, Elements, SubTypes...>
 {
  using type = Container<>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, std :: size_t Elements, class ... SubTypes>
 struct partialSortCopyType <N, Operator, Types...> :: template
	 Implementation<Container, 1u, Elements, SubTypes...>
 {
  using type = Container<typename minType <Operator, SubTypes...> :: type>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, std :: size_t Elements, class ... SubTypes>
 struct partialSortCopyType <N, Operator, Types...> :: template
	 Implementation<Container, Elements, Elements, SubTypes...>
 {
  using type = typename sortType <Operator, SubTypes...> :: template type<Container>;
 };
}
#endif

