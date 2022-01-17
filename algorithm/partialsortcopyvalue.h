#ifndef CRAP_ALGORITHM_PARTIALSORTCOPYVALUE
#define CRAP_ALGORITHM_PARTIALSORTCOPYVALUE

#include "minvalue.h"
#include "partitioncopyvalue.h"
#include "sortvalue.h"
#include "../utility/sizefortype.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, std :: size_t, template <Type, Type> class, Type...> struct partialSortCopyValue;

 template <class Type, template <Type, Type> class Operator> struct partialSortCopyValue<Type, 0u, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator>
	 struct partialSortCopyValue<Type, N, Operator>
 { //Always fail due to above specialisation.
  static_assert(N <= 0u, "Index out of range.");
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct partialSortCopyValue<Type, 0u, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct partialSortCopyValue<Type, 1u, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Value>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type Value>
	 struct partialSortCopyValue<Type, N, Operator, Value>
 { //Always fail due to two above specialisations.
  static_assert(N <= 1u, "Index out of range.");
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct partialSortCopyValue<Type, 0u, Operator, Value1, Value2>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct partialSortCopyValue<Type, 1u, Operator, Value1, Value2>
 {
  private:
  template <template <Type...> class Container> struct Implementation;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Implementation <Container> :: type;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct partialSortCopyValue<Type, 2u, Operator, Value1, Value2>
 {
  private:
  template <template <Type...> class Container> struct Implementation;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Implementation <Container> :: type;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct partialSortCopyValue<Type, N, Operator, Value1, Value2>
 { //Always fail due to three above specialisations.
  static_assert(N <= 2u, "Index out of range.");
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 struct partialSortCopyValue<Type, 0u, Operator, Values...>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 struct partialSortCopyValue<Type, 1u, Operator, Values...>
 {
  private:
  template <template <Type...> class Container> struct Implementation;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Implementation <Container> :: type;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 struct partialSortCopyValue
 {
  private:
  static_assert(N <= sizeof...(Values), "Index out of range.");
  template <template <Type...> class Container, std :: size_t NewN, std :: size_t Elements, Type ... SubValues>
	  struct Implementation;
  template <template <Type...> class Container>
	  struct Implementation<Container, 0u, 0u>;
  template <template <Type...> class Container, Type SubValue>
	  struct Implementation<Container, 0u, 1u, SubValue>;
  template <template <Type...> class Container, Type SubValue>
	  struct Implementation<Container, 1u, 1u, SubValue>;
  template <template <Type...> class Container, Type SubValue1, Type SubValue2>
	  struct Implementation<Container, 0u, 2u, SubValue1, SubValue2>;
  template <template <Type...> class Container, Type SubValue1, Type SubValue2>
	  struct Implementation<Container, 1u, 2u, SubValue1, SubValue2>;
  template <template <Type...> class Container, Type SubValue1, Type SubValue2>
	  struct Implementation<Container, 2u, 2u, SubValue1, SubValue2>;
  template <template <Type...> class Container, std :: size_t Elements, Type ... SubValues>
	  struct Implementation<Container, 0u, Elements, SubValues...>;
  template <template <Type...> class Container, std :: size_t Elements, Type ... SubValues>
	  struct Implementation<Container, 1u, Elements, SubValues...>;
  template <template <Type...> class Container, std :: size_t Elements, Type ... SubValues>
	  struct Implementation<Container, Elements, Elements, SubValues...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Implementation <Container, N, sizeof...(Values), Values...> :: type;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 template <template <Type...> class Container>
 struct partialSortCopyValue <Type, 1u, Operator, Value1, Value2> :: Implementation
 {
  using type = Container<(Operator <Value2, Value1> :: value ? Value2 : Value1)>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 template <template <Type...> class Container>
 struct partialSortCopyValue <Type, 2u, Operator, Value1, Value2> :: Implementation
 {
  using type = Container<
	(Operator <Value2, Value1> :: value ? Value2 : Value1),
	(Operator <Value2, Value1> :: value ? Value1 : Value2)>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container>
 struct partialSortCopyValue <Type, 1u, Operator, Values...> :: Implementation
 {
  using type = Container<minValue <Type, Operator, Values...> :: value>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container, std :: size_t NewN, std :: size_t Elements, Type ... SubValues>
 struct partialSortCopyValue <Type, N, Operator, Values...> :: Implementation
 {
  private:
  using values = valueList<Type, SubValues...>;
  constexpr const static Type pivot = values :: template At <NewN> :: value;
  template <Type Value> using lowerCompare = Operator<pivot, Value>;
  template <Type Value> using upperCompare = Operator<Value, pivot>;
  template <Type ... SubSubValues> using lowerPartitioner = partitionCopyValue<Type, lowerCompare, SubSubValues...>;
  template <Type ... SubSubValues> using upperPartitioner = partitionCopyValue<Type, upperCompare, SubSubValues...>;
  using lowerPartitioned = typename values :: template till<N, lowerPartitioner>;
  using upperPartitioned = typename values :: template since<N + 1u, upperPartitioner>;
  using lowerFailed = typename lowerPartitioned :: template resultTrue<concatenateForType <Type> :: template type>;
  using upperFailed = typename upperPartitioned :: template resultTrue<concatenateForType <Type> :: template type>;
  template <template <Type...> class SubContainer>
	  using lowerFinal = typename lowerPartitioned :: template
	  resultFalse<upperFailed :: template with> :: template type<SubContainer>;
  template <template <Type...> class SubContainer>
	  using upperFinal = typename upperPartitioned :: template
	  resultFalse<lowerFailed :: template with> :: template type<SubContainer>;
  constexpr const static std :: size_t lowerSize = lowerFinal <sizeForType <Type> :: template type> :: value;
  template <Type ... SubSubValues>
	  using lowerPartialSorter = Implementation<concatenateForType <Type> :: template type,
		((NewN < lowerSize) ? NewN : lowerSize), sizeof...(SubSubValues), SubSubValues...>;
  using lower = typename lowerFinal<lowerPartialSorter> :: type;
  using middle = typename
	  std :: conditional<(NewN > lowerSize), typename lower :: template with<pivot>, lower> :: type;
  template <Type ... SubSubValues>
	  using upperPartialSorter = Implementation<middle :: template with,
		((NewN > lowerSize) ? (NewN - (lowerSize + 1u)) : 0u), sizeof...(SubSubValues), SubSubValues...>;
  public:
  using type = typename upperFinal<upperPartialSorter> :: type :: template type<Container>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container>
 struct partialSortCopyValue <Type, N, Operator, Values...> :: template
	 Implementation<Container, 0u, 0u>
 {
  using type = Container<>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container, Type SubValue>
 struct partialSortCopyValue <Type, N, Operator, Values...> :: template
	 Implementation<Container, 0u, 1u, SubValue>
 {
  using type = Container<>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container, Type SubValue>
 struct partialSortCopyValue <Type, N, Operator, Values...> :: template
	 Implementation<Container, 1u, 1u, SubValue>
 {
  using type = Container<SubValue>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container, Type SubValue1, Type SubValue2>
 struct partialSortCopyValue <Type, N, Operator, Values...> :: template
	 Implementation<Container, 0u, 2u, SubValue1, SubValue2>
 {
  using type = Container<>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container, Type SubValue1, Type SubValue2>
 struct partialSortCopyValue <Type, N, Operator, Values...> :: template
	 Implementation<Container, 1u, 2u, SubValue1, SubValue2>
 {
  using type = Container<Operator <SubValue2, SubValue1> :: value ? SubValue2 : SubValue1>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container, Type SubValue1, Type SubValue2>
 struct partialSortCopyValue <Type, N, Operator, Values...> :: template
	 Implementation<Container, 2u, 2u, SubValue1, SubValue2>
 {
  using type = Container<
	  (Operator <SubValue2, SubValue1> :: value ? SubValue2 : SubValue1),
	  (Operator <SubValue2, SubValue1> :: value ? SubValue1 : SubValue2)>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container, std :: size_t Elements, Type ... SubValues>
 struct partialSortCopyValue <Type, N, Operator, Values...> :: template
	 Implementation<Container, 0u, Elements, SubValues...>
 {
  using type = Container<>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container, std :: size_t Elements, Type ... SubValues>
 struct partialSortCopyValue <Type, N, Operator, Values...> :: template
	 Implementation<Container, 1u, Elements, SubValues...>
 {
  using type = Container<minValue <Type, Operator, SubValues...> :: value>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container, std :: size_t Elements, Type ... SubValues>
 struct partialSortCopyValue <Type, N, Operator, Values...> :: template
	 Implementation<Container, Elements, Elements, SubValues...>
 {
  using type = typename sortValue <Type, Operator, SubValues...> :: template type<Container>;
 };
}
#endif

