#ifndef CRAP_ALGORITHM_SETUNIONVALUE
#define CRAP_ALGORITHM_SETUNIONVALUE

#include "equalrangevalue.h"
#include "../utility/valuelist.h"
#include "../utility/valuelistfortype.h"
#include "../utility/valuemultiplexer.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...>
	 struct setUnionValue;

 template <class Type, template <Type, Type> class Operator>
	 struct setUnionValue<Type, Operator>
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct setUnionValue<Type, Operator, Value>
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 struct setUnionValue
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator>
	 template <Type ... Values2>
	 struct setUnionValue <Type, Operator> :: with
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Values2...>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 template <Type ... Values2>
	 struct setUnionValue <Type, Operator, Value> :: with
 {
  private:
  using values2 = valueList<Type, Values2...>;
  using ranges = equalRangeValue<Type, Value, Operator, Values2...>;
  template <Type ... LowerValues> struct specialMerger;
  template <Type ... UpperValues>
	  using lower = typename values2 :: template till <(ranges :: begin), specialMerger> :: template with<UpperValues...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename values2 :: template since <(ranges :: end), lower> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2>
	 struct setUnionValue <Type, Operator, Values1...> :: with
 {
  private:
  template <template <Type...> class Container> using emptySource = Container<Values1...>;
  struct nonEmpty;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename valueMultiplexer <Type, (sizeof...(Values2) == 0u), Container, emptySource, nonEmpty :: template source> :: type;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 template <Type ... Values2>
	 template <Type ... LowerValues>
	 struct setUnionValue <Type, Operator, Value> :: template with <Values2...> :: specialMerger
 {
  template <Type ... UpperValues> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2>
	 struct setUnionValue <Type, Operator, Values1...> :: template with <Values2...> :: nonEmpty
 {
  private:
  using values1 = valueList<Type, Values1...>;
  using values2 = valueList<Type, Values2...>;
  constexpr const static std :: size_t half = (values1 :: size) / 2u;
  constexpr const static Type pivot = values1 :: template At <half> :: value;
  using ranges = equalRangeValue<Type, pivot, Operator, Values2...>;
  template <Type ... SubValues> using This = setUnionValue<Type, Operator, SubValues...>;
  template <Type ... SubValues>
	  using lower1 = typename values1 :: template till <half, This> :: template with<SubValues...>;
  template <Type ... SubValues>
	  using upper1 = typename values1 :: template since <half + 1u, This> :: template with<SubValues...>;
  template <template <Type...> class Container>
	  using lower = typename values2 :: template till <(ranges :: begin), lower1> :: template type<Container>;
  template <template <Type...> class Container>
	  using upper = typename values2 :: template since <(ranges :: end), upper1> :: template type<Container>;
  template <Type Pivot, Type ... LowerValues> struct specialMerger;
  template <Type ... LowerValues> using specialMergerForThis = specialMerger<pivot, LowerValues...>;
  template <Type ... SubValues> using lowerToMerge = typename lower<specialMergerForThis> :: template with<SubValues...>;
  public:
  template <template <Type...> class Container>
	  using source = typename upper <lowerToMerge> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 template <Type ... Values2>
	 template <Type ... LowerValues>
	 template <Type ... UpperValues>
	 struct setUnionValue <Type, Operator, Value> :: template with <Values2...> :: template specialMerger <LowerValues...> :: with
 {
  template <template <Type...> class Container>
	  using type = Container<LowerValues..., Value, UpperValues...>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2>
	 template <Type Pivot, Type ... LowerValues>
	 struct setUnionValue <Type, Operator, Values1...> :: template with <Values2...> :: nonEmpty :: specialMerger
 {
  template <Type ... UpperValues> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2>
	 template <Type Pivot, Type ... LowerValues>
	 template <Type ... UpperValues>
	 struct setUnionValue <Type, Operator, Values1...> :: template with <Values2...> :: nonEmpty :: template specialMerger <Pivot, LowerValues...> :: with
 {
  template <template <Type...> class Container>
	  using type = Container<LowerValues..., Pivot, UpperValues...>;
 };
}
#endif

