#ifndef CRAP_ALGORITHM_MERGEVALUE
#define CRAP_ALGORITHM_MERGEVALUE

#include "copyvalue.h"
#include "equalrangevalue.h"
#include "../utility.d/valuedemultiplexer.h"
#include "../utility.d/valuelist.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct mergeValue;

 template <class Type, template <Type, Type> class Operator> struct mergeValue<Type, Operator>
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> struct mergeValue
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator> template <Type ... Values2>
	 struct mergeValue <Type, Operator> :: with
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = Container<Values2...>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2>
 struct mergeValue <Type, Operator, Values1...> :: with
 {
  private:
  template <Type ... NonEmptyValues2> struct Implementation;
  template <Type ... EmptyValues2> using copy = copyValue<Type, Values1...>;
  constexpr const static bool isEmpty = (sizeof...(Values2) == 0u);
  template <template <Type...> class Container> using Values2Source = Container<Values2...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename valueDemultiplexer <Type, isEmpty, Values2Source, copy, Implementation> :: type :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2> template <Type ... NonEmptyValues2>
struct mergeValue <Type, Operator, Values1...> :: template
	with <Values2...> :: Implementation
 {
  private:
  using values1 = valueList<Type, Values1...>;
  using values2 = valueList<Type, NonEmptyValues2...>;
  constexpr const static Type pivot = values1 :: template At <(values1 :: size) / 2u> :: value;
  template <Type ... LowerValues> struct merge;
  using values1Ranges = equalRangeValue<Type, pivot, Operator, Values1...>;
  using values2Ranges = equalRangeValue<Type, pivot, Operator, NonEmptyValues2...>;
  template <Type ... SubValues> using This = mergeValue<Type, Operator, SubValues...>;
  template <Type ... Lower2Values>
	  using LowerInitial = typename values1 :: template
	  till<(values1Ranges :: begin), This> :: template with<Lower2Values...>;
  template <Type ... Upper2Values>
	  using UpperInitial = typename values1 :: template
	  since<(values1Ranges :: end), This> :: template with<Upper2Values...>;
  template <template <Type...> class Container>
	  using Lower = typename values2 :: template
	  till <(values2Ranges :: begin), LowerInitial> :: template type<Container>;
  template <template <Type...> class Container>
	  using Equal1 = typename values1 :: template
	  subRange<(values1Ranges :: begin), (values1Ranges :: end), Container>;
  template <template <Type...> class Container>
	  using Equal2 = typename values2 :: template
	  subRange<(values2Ranges :: begin), (values2Ranges :: end), Container>;
  template <template <Type...> class Container>
	  using Upper = typename values2 :: template
	  since <(values2Ranges :: end), UpperInitial> :: template type<Container>;
  template <Type ... Values1Equal>
	  using ans1 = typename Lower <merge> :: template withValues1Equal<Values1Equal...>;
  template <Type ... Values2Equal>
	  using ans2 = typename Equal1 <ans1> :: template withValues2Equal<Values2Equal...>;
  template <Type ... Upper> using ans3 = typename Equal2 <ans2> :: template withUpper<Upper...>;
  public:
  template <template <Type...> class Container>
	  using type = typename Upper <ans3> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2> template <Type ... NonEmptyValues2>
	 template <Type ... LowerValues>
 struct mergeValue <Type, Operator, Values1...> :: template
 	with <Values2...> :: template Implementation <NonEmptyValues2...> :: merge
 {
  template <Type ... Values1Equal> struct withValues1Equal;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2> template <Type ... NonEmptyValues2>
	 template <Type ... LowerValues> template <Type ... Values1Equal>
 struct mergeValue <Type, Operator, Values1...> :: template with <Values2...> :: template
 	Implementation <NonEmptyValues2...> :: template merge <LowerValues...> :: withValues1Equal
 {
  template <Type ... Values2Equal> struct withValues2Equal;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2> template <Type ... NonEmptyValues2>
	 template <Type ... LowerValues> template <Type ... Values1Equal>
	 template <Type ... Values2Equal>
 struct mergeValue <Type, Operator, Values1...> :: template
 	with <Values2...> :: template Implementation <NonEmptyValues2...> :: template
	merge <LowerValues...> :: template withValues1Equal <Values1Equal...> :: withValues2Equal
 {
  template <Type ... UpperValues> struct withUpper;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2> template <Type ... NonEmptyValues2>
	 template <Type ... LowerValues> template <Type ... Values1Equal>
	 template <Type ... Values2Equal> template <Type ... UpperValues>
 struct mergeValue <Type, Operator, Values1...> :: template
 	with <Values2...> :: template Implementation <NonEmptyValues2...> :: template
	merge <LowerValues...> :: template withValues1Equal <Values1Equal...> :: template
	withValues2Equal <Values2Equal...> :: withUpper
 {
  template <template <Type...> class Container>
	  using type = Container<LowerValues..., Values1Equal..., Values2Equal..., UpperValues...>;
 };
}
#endif

