#ifndef CRAP_ALGORITHM_NTHELEMENTVALUE
#define CRAP_ALGORITHM_NTHELEMENTVALUE

#include "copyvalue.h"
#include "partitionvalue.h"
#include "../utility.d/concatenatefortype.h"
#include "../utility.d/valuedemultiplexer.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, std :: size_t, template <Type, Type> class, Type...> struct NthElementValue;

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type Value> struct NthElementValue<Type, N, Operator, Value>
 {
  private:
  static_assert(N < 1u, "Index out of range.");
  public:
  constexpr const static Type value = Value;
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Value>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type Value1, Type Value2> struct NthElementValue<Type, N, Operator, Value1, Value2>
 {
  private:
  static_assert(N < 2u, "Index out of range.");
  constexpr const static auto sorted = Operator <Value1, Value2> :: value;
  constexpr const static Type first = (sorted ? Value1 : Value2);
  constexpr const static Type second = (sorted ? Value2 : Value1);
  public:
  constexpr const static Type value = ((N == 0u) ? first : second);
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<first, second>;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values> struct NthElementValue
 {
  private:
  using values = valueList<Type, Values...>;
  static_assert(N < (values :: size), "Index out of range.");
  constexpr const static Type pivot = values :: template At <N> :: value;
  template <Type Value> using lowerCompare = Operator<pivot, Value>;
  template <Type Value> using upperCompare = Operator<Value, pivot>;
  template <Type ... SubValues> using lowerPartitioner = partitionValue<Type, lowerCompare, SubValues...>;
  template <Type ... SubValues> using upperPartitioner = partitionValue<Type, upperCompare, SubValues...>;
  template <Type Pivot, Type ... LowerValues> struct specialMerger;
  template <Type ... LowerValues> using specialMergerForThis = specialMerger<pivot, LowerValues...>; 
  using lowerPartitioned = typename values :: template till<N, lowerPartitioner>;
  using upperPartitioned = typename values :: template since<N + 1u, upperPartitioner>;
  using lowerFailed = typename lowerPartitioned :: template type <> :: template till<lowerPartitioned :: value, concatenateForType <Type> :: template values>;
  using upperFailed = typename upperPartitioned :: template type <> :: template till<upperPartitioned :: value, concatenateForType <Type> :: template values>;
  using lowerMerged = typename lowerPartitioned :: template type <> :: template since<lowerPartitioned :: value, upperFailed :: template with>;
  using upperMerged = typename upperPartitioned :: template type <> :: template since<upperPartitioned :: value, lowerFailed :: template with>;
  constexpr const static std :: size_t lowerSize = lowerMerged :: template type <> :: size;
  template <Type ... SubValues> using lowerSorter = NthElementValue<Type, N, Operator, SubValues...>;
  template <Type ... SubValues> using upperSorter = NthElementValue<Type, N - (lowerSize + 1u), Operator, SubValues...>;
  template <Type ... SubValues> using blanc = copyValue<Type, SubValues...>;
  using lower = typename valueDemultiplexer<Type, (N < lowerSize), lowerMerged :: template type, lowerSorter, blanc> :: type;
  using upper = typename valueDemultiplexer<Type, (N > lowerSize), upperMerged :: template type, upperSorter, blanc> :: type;
  using ans1 = typename lower :: template type<specialMergerForThis>;
  using ans2 = typename upper :: template type<ans1 :: template with>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = typename ans2 :: template type<Container>;
  constexpr const static Type value = ans2 :: template type <> :: template At <N> :: value;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values> template <Type Pivot, Type ... LowerValues>
	 struct NthElementValue <Type, N, Operator, Values...> :: specialMerger
 {
  template <Type ... UpperValues> struct with;
 };

 template <class Type, std :: size_t N, template <Type, Type> class Operator, Type ... Values>
	 template <Type Pivot, Type ... LowerValues> template <Type ... UpperValues>
	 struct NthElementValue <Type, N, Operator, Values...> :: template specialMerger <Pivot, LowerValues...> :: with
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<LowerValues..., Pivot, UpperValues...>;
 };
}
#endif

