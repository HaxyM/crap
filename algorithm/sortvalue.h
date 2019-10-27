#ifndef CRAP_ALGORITHM_SORTVALUE
#define CRAP_ALGORITHM_SORTVALUE

#include "partitionvalue.h"
#include "../utility/concatenatevalue.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct sortValue;

 template <class Type, template <Type, Type> class Operator> struct sortValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value> struct sortValue<Type, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<Value>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2> struct sortValue<Type, Operator, Value1, Value2>
 {
  private:
  constexpr const static bool sorted = Operator <Value1, Value2> :: value;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<(sorted ? Value1 : Value2), (sorted ? Value2 : Value1)>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct sortValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  constexpr const static auto pivot = values :: template At <half> :: value;
  template <Type Pivot, Type ... LowerValues> struct finalMerger;
  template <Type Value> using lowerOperator = Operator<pivot, Value>;
  template <Type Value> using upperOperator = Operator<Value, pivot>;
  template <Type ... SubValues> using merger = concatenateValue<Type, SubValues...>;
  template <Type ... SubValues> using This = sortValue<Type, Operator, SubValues...>;
  template <Type ... LowerValues> using finalMergerForThis = finalMerger<pivot, LowerValues...>;
  template <Type ... SubValues> using lowerPartition = partitionValue<Type, lowerOperator, SubValues...>;
  template <Type ... SubValues> using upperPartition = partitionValue<Type, upperOperator, SubValues...>;
  using lowerPartitioned = typename values :: template till<half, lowerPartition>;
  using upperPartitioned = typename values :: template since<half + 1u, upperPartition>;
  using lowerFailed = typename lowerPartitioned :: template type <> :: template till<lowerPartitioned :: value, merger>;
  using upperFailed = typename upperPartitioned :: template type <> :: template till<upperPartitioned :: value, merger>;
  using lowerPassed = typename lowerPartitioned :: template type <> :: template since<lowerPartitioned :: value, upperFailed :: template with>;
  using upperPassed = typename upperPartitioned :: template type <> :: template since<upperPartitioned :: value, lowerFailed :: template with>;
  using lower = typename lowerPassed :: template type<This>;
  using upper = typename upperPassed :: template type<This>;
  using ans1 = typename lower :: template type<finalMergerForThis>;
  using ans2 = typename upper :: template type<ans1 :: template with>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename ans2 :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> template <Type Pivot, Type ... LowerValues>
	 struct sortValue <Type, Operator, Values...> :: finalMerger
 {
  template <Type ... UpperValues> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 template <Type Pivot, Type ... LowerValues> template <Type ... UpperValues>
	 struct sortValue <Type, Operator, Values...> :: template finalMerger <Pivot, LowerValues...> :: with
 {
  template <template <Type...> class Container> using type = Container<LowerValues..., Pivot, UpperValues...>;
 };
}
#endif

