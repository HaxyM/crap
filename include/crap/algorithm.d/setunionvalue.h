#ifndef CRAP_ALGORITHM_SETUNIONVALUE
#define CRAP_ALGORITHM_SETUNIONVALUE

#include "copyvalue.h"
#include "equalrangevalue.h"
#include "../utility.d/concatenatevaluezipper.h"
#include "../utility.d/valuelist.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...>
	 struct setUnionValue;

 template <class Type, template <Type, Type> class Operator>
	 struct setUnionValue<Type, Operator>
 {
  template <Type ... Values2> using with = copyValue<Type, Values2...>;
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

 template <class Type, template <Type, Type> class Operator, Type Value>
	 template <Type ... Values2>
	 struct setUnionValue <Type, Operator, Value> :: with
 {
  private:
  using values2 = valueList<Type, Values2...>;
  using range = equalRangeValue<Type, Value, Operator, Values2...>;
  constexpr const static std :: size_t newBegin = (((range :: begin) == (range :: end)) ? (range :: begin) : ((range :: begin) + 1u));
  template <template <Type...> class Container> using middle = typename copyValue <Type, Value> :: template type<Container>;
  template <template <Type...> class Container> using lower = typename values2 :: template till<(range :: begin), Container>;
  template <template <Type...> class Container> using upper = typename values2 :: template since<newBegin, Container>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename concatenateValueZipper <Type, lower, middle, upper> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2>
	 struct setUnionValue <Type, Operator, Values1...> :: with
 {
  private:
  using values1 = valueList<Type, Values1...>;
  using values2 = valueList<Type, Values2...>;
  constexpr const static Type midValue = values1 :: template At <(values1 :: size) / 2u> :: value;
  using range1 = equalRangeValue<Type, midValue, Operator, Values1...>;
  using range2 = equalRangeValue<Type, midValue, Operator, Values2...>;
  constexpr const static std :: size_t range1Size = ((range1 :: end) - (range1 :: begin));
  constexpr const static std :: size_t range2NewBegin = (range2 :: begin) + range1Size;
  constexpr const static std :: size_t range2Begin = ((range2NewBegin < (range2 :: end)) ? range2NewBegin : (range2 :: end));
  template <Type ... SubValues> using This = setUnionValue<Type, Operator, SubValues...>;
  template <template <Type...> class Container> using middle1 = typename values1 :: template subRange<(range1 :: begin), (range1 :: end), Container>;
  template <template <Type...> class Container> using middle2 = typename values2 :: template subRange<range2Begin, (range2 :: end), Container>;
  template <template <Type...> class Container>
	  using lower = typename values2 :: template
	  till <(range2 :: begin), values1 :: template till <(range1 :: begin), This> :: template with> :: template type<Container>;
  template <template <Type...> class Container>
	  using upper = typename values2 :: template
	  since <(range2 :: end), values1 :: template since <(range1 :: end), This> :: template with> :: template type<Container>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename concatenateValueZipper <Type, lower, middle1, middle2, upper> :: template type<Container>;
 };
}
#endif

