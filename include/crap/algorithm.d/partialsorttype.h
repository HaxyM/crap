#ifndef CRAP_ALGORITHM_PARTIALSORTTYPE
#define CRAP_ALGORITHM_PARTIALSORTTYPE

#include "copytype.h"
#include "partitioncopytype.h"
#include "sorttype.h"
#include "../utility.d/typedemultiplexer.h"
#include "../utility.d/concatenatetype.h"
#include "../utility.d/typelist.h"

namespace crap
{
 template <std :: size_t, template <class, class> class, class...> struct partialSortType;

 template <std :: size_t N, template <class, class> class Operator, class Type>
	 struct partialSortType<N, Operator, Type>
 {
  static_assert(N < 1u, "Index out of range.");
  template <template <class...> class Container = typeList>
	  using type = Container<Type>;
 };

 template <std :: size_t N, template <class, class> class Operator, class ... Types> struct partialSortType
 {
  private:
  static_assert(N < sizeof...(Types), "Index out of range.");
  using types = typeList<Types...>;
  using pivot = typename types :: template at<N>;
  template <class Type> using lowerCompare = Operator<pivot, Type>;
  template <class Type> using upperCompare = Operator<Type, pivot>;
  template <class ... SubTypes> using lowerPartitioner = partitionCopyType<lowerCompare, SubTypes...>;
  template <class ... SubTypes> using upperPartitioner = partitionCopyType<upperCompare, SubTypes...>;
  using lowerPartitioned = typename types :: template till<N, lowerPartitioner>;
  using upperPartitioned = typename types :: template since<N + 1u, upperPartitioner>;
  using lowerFailed = typename lowerPartitioned :: template resultTrue<concatenateType>;
  using upperFailed = typename upperPartitioned :: template resultTrue<concatenateType>;
  template <template <class...> class Container = typeList>
	  using lowerFinal = typename lowerPartitioned :: template resultFalse<upperFailed :: template with> :: template type<Container>;
  template <template <class...> class Container>
	  using upperFinal = typename upperPartitioned :: template resultFalse<lowerFailed :: template with> :: template type<Container>;
  constexpr const static std :: size_t lowerSize = lowerFinal <> :: size;
  template <class ... SubTypes> using sorter = sortType<Operator, SubTypes...>;
  template <class ... SubTypes> using lowerPartialSorter = partialSortType<N, Operator, SubTypes...>;
  template <class ... SubTypes>
	  using upperPartialSorter = partialSortType<N - (lowerSize + 1u), Operator, SubTypes...>;
  using lower = typename typeDemultiplexer<(N < lowerSize), lowerFinal, lowerPartialSorter, sorter> :: type;
  using upper = typename typeDemultiplexer<(N > lowerSize), upperFinal, upperPartialSorter, copyType> :: type;
  using ans1 = typename lower :: template type<concatenateType>;
  using ans2 = typename ans1 :: template with<pivot>;
  using ans3 = typename upper :: template type<ans2 :: template with>;
  public:
  template <template <class...> class Container = typeList>
	  using type = typename ans3 :: template type<Container>;
 };
}
#endif

