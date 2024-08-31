#ifndef CRAP_ALGORITHM_SHUFFLETYPE
#define CRAP_ALGORITHM_SHUFFLETYPE

#include <cstddef>

#include "../iterator.d/sizefortype.h"
#include "../utility.d/bisectvalue.h"
#include "../utility.d/swapindicestype.h"
#include "../utility.d/typelist.h"

namespace crap
{
 template <class...> struct shuffleType;

 template <> struct shuffleType<>
 {
  template <std :: size_t ... Random> struct with;
 };

 template <class Type> struct shuffleType<Type>
 {
  template <std :: size_t ... Random> struct with;
 };

 template <class Type1, class Type2> struct shuffleType<Type1, Type2>
 {
  template <std :: size_t ... Random> struct with;
  template <std :: size_t Random1, std :: size_t Random2> struct with<Random1, Random2>;
 };

 template <class ... Types> struct shuffleType
 {
  template <std :: size_t ... Random> struct with;
 };

 template <std :: size_t ... Random> struct shuffleType <> :: with
 {
  static_assert(sizeof...(Random) == 0u, "Vectors does not have same size.");
  template <template <class...> class Container = typeList>
	  using type = Container<>;
 };

 template <class Type> template <std :: size_t ... Random> struct shuffleType <Type> :: with
 {
  static_assert(sizeof...(Random) == 1u, "Vectors does not have same size.");
  template <template <class...> class Container = typeList>
	  using type = Container<Type>;
 };

 template <class Type1, class Type2> template <std :: size_t ... Random>
	 struct shuffleType <Type1, Type2> :: with
 { //Always fail due to below specification.
  static_assert(sizeof...(Random) != 2u, "Vectors does not have same size.");
 };

 template <class Type1, class Type2> template <std :: size_t Random1, std :: size_t Random2>
	 struct shuffleType <Type1, Type2> :: template with<Random1, Random2>
 {
  private:
  template <template <class...> class Container, bool> struct Implementation;
  template <template <class...> class Container> struct Implementation<Container, false>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Implementation <Container, ((Random1 % 2u) != (Random2 % 2u))> :: type;
 };

 template <class ... Types> template <std :: size_t ... Random>
	 struct shuffleType <Types...> :: with
 {
  private:
  static_assert(sizeof...(Random) == sizeof...(Types), "Vectors does not have same size.");
  template <template <class...> class Container, std :: size_t Offset, class ... SubTypes> struct Implementation;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename Implementation <Container, 0u, Types...> :: template
	  withImplementation <Random...> :: type;
 };

 template <class Type1, class Type2>
	 template <std :: size_t Random1, std :: size_t Random2>
	 template <template <class...> class Container, bool>
 struct shuffleType <Type1, Type2> :: template with <Random1, Random2> :: Implementation
 {
  using type = Container<Type1, Type2>;
 };

 template <class Type1, class Type2>
	 template <std :: size_t Random1, std :: size_t Random2>
	 template <template <class...> class Container>
 struct shuffleType <Type1, Type2> :: template with <Random1, Random2> :: template
	 Implementation<Container, false>
 {
  using type = Container<Type2, Type1>;
 };

 template <class ... Types>
	 template <std :: size_t ... Random>
	 template <template <class...> class Container, std :: size_t Offset, class ... SubTypes>
 struct shuffleType <Types...> :: template with <Random...> :: Implementation
 {
  template <std :: size_t ... SubRandom> struct withImplementation;
  template <std :: size_t SubRandom> struct withImplementation<SubRandom>;
 };

 template <class ... Types>
	 template <std :: size_t ... Random>
	 template <template <class...> class Container, std :: size_t Offset, class ... SubTypes>
	 template <std :: size_t ... SubRandom>
 struct shuffleType <Types...> :: template with <Random...> :: template
	 Implementation <Container, Offset, SubTypes...> :: withImplementation
 {
  private:
  using indices = bisectValue<std :: size_t, SubRandom...>;
  template <class ... SubSubTypes> using lower = typename indices :: template
	  lower<Implementation <Container, Offset, SubSubTypes...> :: template withImplementation> :: type;
  constexpr const static std :: size_t upperOffset = Offset
	  + indices :: template lower <sizeForType <std :: size_t> :: template type> :: value;
  public:
  using type = typename indices :: template
	  upper <Implementation <lower, upperOffset, SubTypes...> :: template withImplementation> :: type;
 };

 template <class ... Types>
	 template <std :: size_t ... Random>
	 template <template <class...> class Container, std :: size_t Offset, class ... SubTypes>
	 template <std :: size_t SubRandom>
 struct shuffleType <Types...> :: template with <Random...> :: template
	 Implementation <Container, Offset, SubTypes...> :: template withImplementation<SubRandom>
 {
  private:
  constexpr const static auto newIndex = SubRandom % sizeof...(SubTypes);
  public:
  using type = typename swapIndicesType <Offset, newIndex, SubTypes...> :: template type<Container>;
 };
}
#endif

