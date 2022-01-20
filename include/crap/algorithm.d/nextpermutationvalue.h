#ifndef CRAP_ALGORITHM_NEXTPERMUTATIONVALUE
#define CRAP_ALGORITHM_NEXTPERMUTATIONVALUE

#include "issorteduntilfortype.h"
#include "reversefortype.h"
#include "reversevalue.h"
#include "upperboundfortype.h"
#include "../utility.d/concatenatefortype.h"
#include "../utility.d/splitfortype.h"
#include "../utility.d/swapindicesvalue.h"
#include "../utility.d/valuelist.h"
#include "../utility.d/valuelistfortype.h"
#include "../utility.d/valuemultiplexer.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator, Type ... Values> struct nextPermutationValue
 {
  private:
  using findPivot = typename reverseValue <Type, Values...> :: template type<isSortedUntilForType<Type, Operator> :: template type>;
  template <template <Type...> class Container, std :: size_t Pivot> struct permutator;
  template <template <Type...> class Container>
	  using permute = typename permutator <Container, (sizeof...(Values) - (findPivot :: value) - 1u)> :: type;
  template <template <Type...> class Container> using finish = typename reverseValue <Type, Values...> :: template type<Container>;
  public:
  constexpr const static bool value = ((findPivot :: value) != (findPivot :: npos));
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename valueMultiplexer <Type, value, Container, permute, finish> :: type;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container, std :: size_t Pivot>
 struct nextPermutationValue <Type, Operator, Values...> :: permutator
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static Type pivot = values :: template At <Pivot> :: value;
  constexpr const static std :: size_t Index =
	  (values :: size) - (reverseValue <Type, Values...> :: template type <upperBoundForType <Type, pivot, Operator> :: template type> :: value) - 1u;
  using split = typename swapIndicesValue <Type, Pivot, Index, Values...> :: template type<splitForType <Type, Pivot + 1u> :: template type>;
  public:
  using type = typename split :: template upper <reverseForType <Type> :: template type> :: template type<split :: template lower <concatenateForType <Type> :: template type> :: template with> :: template type<Container>;
 };
}
#endif

