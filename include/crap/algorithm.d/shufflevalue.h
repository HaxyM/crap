#ifndef CRAP_ALGORITHM_SHUFFLEVALUE
#define CRAP_ALGORITHM_SHUFFLEVALUE

#include <cstddef>

#include "../iterator.d/sizefortype.h"
#include "../utility.d/bisectvalue.h"
#include "../utility.d/swapindicesvalue.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, Type...> struct shuffleValue;

 template <class Type> struct shuffleValue<Type>
 {
  template <std :: size_t ... Random> struct with;
 };

 template <class Type, Type Value> struct shuffleValue<Type, Value>
 {
  template <std :: size_t ... Random> struct with;
 };

 template <class Type, Type Value1, Type Value2> struct shuffleValue<Type, Value1, Value2>
 {
  template <std :: size_t ... Random> struct with;
  template <std :: size_t Random1, std :: size_t Random2> struct with<Random1, Random2>;
 };

 template <class Type, Type ... Values> struct shuffleValue
 {
  template <std :: size_t ... Random> struct with;
 };

 template <class Type> template <std :: size_t ... Random> struct shuffleValue <Type> :: with
 {
  static_assert(sizeof...(Random) == 0u, "Vectors does not have same size.");
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<>;
 };

 template <class Type, Type Value> template <std :: size_t ... Random> struct shuffleValue <Type, Value> :: with
 {
  static_assert(sizeof...(Random) == 1u, "Vectors does not have same size.");
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Value>;
 };

 template <class Type, Type Value1, Type Value2> template <std :: size_t ... Random>
	 struct shuffleValue <Type, Value1, Value2> :: with
 { //Always fail due to below specification.
  static_assert(sizeof...(Random) != 2u, "Vectors does not have same size.");
 };

 template <class Type, Type Value1, Type Value2> template <std :: size_t Random1, std :: size_t Random2>
	 struct shuffleValue <Type, Value1, Value2> :: template with<Random1, Random2>
 {
  private:
  template <template <Type...> class Container, bool> struct Implementation;
  template <template <Type...> class Container> struct Implementation<Container, false>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Implementation <Container, ((Random1 % 2u) != (Random2 % 2u))> :: type;
 };

 template <class Type, Type ... Values> template <std :: size_t ... Random>
	 struct shuffleValue <Type, Values...> :: with
 {
  private:
  static_assert(sizeof...(Random) == sizeof...(Values), "Vectors does not have same size.");
  template <template <Type...> class Container, std :: size_t Offset, Type ... SubValues> struct Implementation;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Implementation <Container, 0u, Values...> :: template
	  withImplementation <Random...> :: type;
 };

 template <class Type, Type Value1, Type Value2>
	 template <std :: size_t Random1, std :: size_t Random2>
	 template <template <Type...> class Container, bool>
 struct shuffleValue <Type, Value1, Value2> :: template with <Random1, Random2> :: Implementation
 {
  using type = Container<Value1, Value2>;
 };

 template <class Type, Type Value1, Type Value2>
	 template <std :: size_t Random1, std :: size_t Random2>
	 template <template <Type...> class Container>
 struct shuffleValue <Type, Value1, Value2> :: template with <Random1, Random2> :: template
	 Implementation<Container, false>
 {
  using type = Container<Value2, Value1>;
 };

 template <class Type, Type ... Values>
	 template <std :: size_t ... Random>
	 template <template <Type...> class Container, std :: size_t Offset, Type ... SubValues>
 struct shuffleValue <Type, Values...> :: template with <Random...> :: Implementation
 {
  template <std :: size_t ... SubRandom> struct withImplementation;
  template <std :: size_t SubRandom> struct withImplementation<SubRandom>;
 };

 template <class Type, Type ... Values>
	 template <std :: size_t ... Random>
	 template <template <Type...> class Container, std :: size_t Offset, Type ... SubValues>
	 template <std :: size_t ... SubRandom>
 struct shuffleValue <Type, Values...> :: template with <Random...> :: template
	 Implementation <Container, Offset, SubValues...> :: withImplementation
 {
  private:
  using indices = bisectValue<std :: size_t, SubRandom...>;
  template <Type ... SubSubValues> using lower = typename indices :: template
	  lower<Implementation <Container, Offset, SubSubValues...> :: template withImplementation> :: type;
  constexpr const static std :: size_t upperOffset = Offset
	  + indices :: template lower <sizeForType <std :: size_t> :: template type> :: value;
  public:
  using type = typename indices :: template
	  upper <Implementation <lower, upperOffset, SubValues...> :: template withImplementation> :: type;
 };

 template <class Type, Type ... Values>
	 template <std :: size_t ... Random>
	 template <template <Type...> class Container, std :: size_t Offset, Type ... SubValues>
	 template <std :: size_t SubRandom>
 struct shuffleValue <Type, Values...> :: template with <Random...> :: template
	 Implementation <Container, Offset, SubValues...> :: template withImplementation<SubRandom>
 {
  private:
  constexpr const static auto newIndex = SubRandom % sizeof...(SubValues);
  public:
  using type = typename swapIndicesValue <Type, Offset, newIndex, SubValues...> :: template type<Container>;
 };
}
#endif

