#ifndef CRAP_ALGORITHM_PARTIALSORTVALUE
#define CRAP_ALGORITHM_PARTIALSORTVALUE

#include "copyvalue.h"
#include "partitioncopyvalue.h"
#include "sortvalue.h"
#include "../utility/valuedemultiplexer.h"
#include "../utility/concatenatefortype.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, std :: size_t, template <Type, Type> class, Type...> struct partialSortValue;

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type Value> struct partialSortValue<Type, N, Operator, Value>
 {
  static_assert(N < 1u, "Index out of range.");
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Value>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values> struct partialSortValue
 {
  private:
  static_assert(N < sizeof...(Values), "Index out of range.");
  using values = valueList<Type, Values...>;
  constexpr const static Type pivot = values :: template At <N> :: value;
  template <Type Value> using lowerCompare = Operator<pivot, Value>;
  template <Type Value> using upperCompare = Operator<Value, pivot>;
  template <Type ... SubValues> using lowerPartitioner = partitionCopyValue<Type, lowerCompare, SubValues...>;
  template <Type ... SubValues> using upperPartitioner = partitionCopyValue<Type, upperCompare, SubValues...>;
  using lowerPartitioned = typename values :: template till<N, lowerPartitioner>;
  using upperPartitioned = typename values :: template since<N + 1u, upperPartitioner>;
  using lowerFailed = typename lowerPartitioned :: template resultTrue<concatenateForType <Type> :: template values>;
  using upperFailed = typename upperPartitioned :: template resultTrue<concatenateForType <Type> :: template values>;
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using lowerFinal = typename lowerPartitioned :: template resultFalse<upperFailed :: template with> :: template type<Container>;
  template <template <Type...> class Container>
	  using upperFinal = typename upperPartitioned :: template resultFalse<lowerFailed :: template with> :: template type<Container>;
  constexpr const static std :: size_t lowerSize = lowerFinal <> :: size;
  template <Type Pivot, Type ... LowerValues> struct specialMerger;
  template <Type ... LowerValues> using specialMergerForThis = specialMerger<pivot, LowerValues...>; 
  template <Type ... SubValues> using sorter = sortValue<Type, Operator, SubValues...>;
  template <Type ... SubValues> using lowerPartialSorter = partialSortValue<Type, N, Operator, SubValues...>;
  template <Type ... SubValues> using upperPartialSorter = partialSortValue<Type, N - (lowerSize + 1u), Operator, SubValues...>;
  template <Type ... SubValues> using blanc = copyValue<Type, SubValues...>;
  using lower = typename valueDemultiplexer<Type, (N < lowerSize), lowerFinal, lowerPartialSorter, sorter> :: type;
  using upper = typename valueDemultiplexer<Type, (N > lowerSize), upperFinal, upperPartialSorter, blanc> :: type;
  using ans1 = typename lower :: template type<specialMergerForThis>;
  using ans2 = typename upper :: template type<ans1 :: template with>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename ans2 :: template type<Container>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values> template <Type Pivot, Type ... LowerValues>
	 struct partialSortValue <Type, N, Operator, Values...> :: specialMerger
 {
  template <Type ... UpperValues> struct with;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 template <Type Pivot, Type ... LowerValues> template <Type ... UpperValues>
	 struct partialSortValue <Type, N, Operator, Values...> :: template specialMerger <Pivot, LowerValues...> :: with
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<LowerValues..., Pivot, UpperValues...>;
 };
}
#endif

