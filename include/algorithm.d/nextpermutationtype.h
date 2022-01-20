#ifndef CRAP_ALGORITHM_NEXTPERMUTATIONTYPE
#define CRAP_ALGORITHM_NEXTPERMUTATIONTYPE

#include "issorteduntiltype.h"
#include "reversetype.h"
#include "upperboundtype.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/splittype.h"
#include "../utility.d/swapindicestype.h"
#include "../utility.d/typelist.h"
#include "../utility.d/typemultiplexer.h"

#include <cstddef>

namespace crap
{
 template <template <class, class> class Operator, class ... Types> struct nextPermutationType
 {
  private:
  template <class ... SubTypes> using pivotFinder = isSortedUntilType<Operator, SubTypes...>;
  using findPivot = typename reverseType <Types...> :: template type<pivotFinder>;
  template <template <class...> class Container, std :: size_t Pivot> struct permutator;
  template <template <class...> class Container>
	  using permute = typename permutator <Container, (sizeof...(Types) - (findPivot :: value) - 1u)> :: type;
  template <template <class...> class Container>
	  using finish = typename reverseType <Types...> :: template type<Container>;
  public:
  constexpr const static bool value = ((findPivot :: value) != (findPivot :: npos));
  template <template <class...> class Container = typeList>
	  using type = typename typeMultiplexer <value, Container, permute, finish> :: type;
 };

 template <template <class, class> class Operator, class ... Types>
	 template <template <class...> class Container, std :: size_t Pivot>
 struct nextPermutationType <Operator, Types...> :: permutator
 {
  private:
  using pivot = typename typeList <Types...> :: template at<Pivot>;
  template <class ... SubTypes> using swapFinder = upperBoundType<pivot, Operator, SubTypes...>;
  template <class ... SubTypes> using splitter = splitType<Pivot + 1u, SubTypes...>;
  constexpr const static std :: size_t Index =
	  sizeof...(Types) - (reverseType <Types...> :: template type <swapFinder> :: value) - 1u;
  using split = typename swapIndicesType <Pivot, Index, Types...> :: template type<splitter>;
  public:
  using type = typename split :: template upper <reverseType> :: template
	  type <split :: template lower <concatenateType> :: template with> :: template type<Container>;
 };
}
#endif

