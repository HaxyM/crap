#ifndef CRAP_ALGORITHM_PREVPERMUTATIONVALUE
#define CRAP_ALGORITHM_PREVPERMUTATIONVALUE

#include "issorteduntilfortype.h"
#include "reversefortype.h"
#include "reversevalue.h"
#include "upperboundfortype.h"
#include "../utility/concatenatefortype.h"
#include "../utility/splitfortype.h"
#include "../utility/swapindicesvalue.h"
#include "../utility/valuelist.h"
#include "../utility/valuelistfortype.h"
#include "../utility/valuemultiplexer.h"

namespace crap
{
 template <class Type, template <Type, Type> class Operator, Type ... Values> struct prevPermutationValue
 {
  private:
  template <Type Value1, Type Value2> using greater = Operator<Value2, Value1>;
  using findPivot = typename reverseValue <Type, Values...> :: template
	  type<isSortedUntilForType<Type, greater> :: template type>;
  template <template <Type...> class Container, std :: size_t Pivot> struct permutator;
  template <template <Type...> class Container>
	  using permute = typename permutator <Container, (sizeof...(Values) - (findPivot :: value) - 1u)> :: type;
  template <template <Type...> class Container>
	  using finish = typename reverseValue <Type, Values...> :: template type<Container>;
  public:
  constexpr const static bool value = ((findPivot :: value) != (findPivot :: npos));
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename valueMultiplexer <Type, value, Container, permute, finish> :: type;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <template <Type...> class Container, std :: size_t Pivot>
 struct prevPermutationValue <Type, Operator, Values...> :: permutator
 {
  private:
  template <Type Value1, Type Value2> using greater = Operator<Value2, Value1>;
  using values = valueList<Type, Values...>;
  constexpr const static Type pivot = values :: template At <Pivot> :: value;
  constexpr const static std :: size_t Index =
	  (values :: size) - (reverseValue <Type, Values...> :: template type <upperBoundForType <Type, pivot, greater> :: template type> :: value) - 1u;
  using split = typename swapIndicesValue <Type, Pivot, Index, Values...> :: template
	  type<splitForType <Type, Pivot + 1u> :: template type>;
  public:
  using type = typename split :: template upper <reverseForType <Type> :: template type> :: template
	  type <split :: template lower <concatenateForType <Type> :: template type> :: template with> :: template
	  type<Container>;
 };
}
#endif

