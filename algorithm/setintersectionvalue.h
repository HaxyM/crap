#ifndef CRAP_ALGORITHM_SETINTERSECTIONVALUE
#define CRAP_ALGORITHM_SETINTERSECTIONVALUE

#include "equalrangevalue.h"
#include "fillvalue.h"
#include "../utility/concatenatevaluezipper.h"
#include "../utility/nullvalue.h"
#include "../utility/valuelist.h"
#include "../utility/valuelistfortype.h"
#include "../utility/valuemultiplexer.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct setIntersectionValue;

 template <class Type, template <Type, Type> class Operator> struct setIntersectionValue<Type, Operator>
 {
  template <Type...> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> struct setIntersectionValue<Type, Operator, Value1>
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> struct setIntersectionValue
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type,  Type> class Operator>
	 template <Type...>
 struct setIntersectionValue <Type, Operator> :: with
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type> using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1>
	 template <Type ... Values2>
 struct setIntersectionValue <Type, Operator, Value1> :: with
 {
  private:
  using found = equalRangeValue<Type, Value1, Operator, Values2...>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename valueMultiplexer <Type, (found :: begin == found :: end), Container, nullValue <Type> :: template type, fillValue <Type, 1u, Value1> :: template type> :: type;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
	 template <Type ... Values2>
 struct setIntersectionValue <Type, Operator, Values1...> :: with
 {
  private:
  template <Type ... SubValues> using This = setIntersectionValue<Type, Operator, SubValues...>;
  using values1 = valueList<Type, Values1...>;
  using values2 = valueList<Type, Values2...>;
  constexpr const static Type midValue = values1 :: template At <(values1 :: size) / 2u> :: value;
  using range1 = equalRangeValue<Type, midValue, Operator, Values1...>;
  using range2 = equalRangeValue<Type, midValue, Operator, Values2...>;
  constexpr const static std :: size_t range1Size = (range1 :: end) - (range1 :: begin);
  constexpr const static std :: size_t range2Size = (range2 :: end) - (range2 :: begin);
  constexpr const static std :: size_t mid1End = (range1Size < range2Size) ? (range1 :: end) : ((range1 :: begin) + range2Size);
  template <template <Type...> class Container>
	  using front = typename values2 :: template till <range2 :: begin, values1 :: template till<range1 :: begin, This> :: template with> :: template type<Container>;
  template <template <Type...> class Container>
	  using back = typename values2 :: template since <range2 :: end, values1 :: template since<range1 :: end, This> :: template with> :: template type<Container>;
  template <template <Type...> class Container>
	  using middle = typename values1 :: template subRange<(range1 :: begin), mid1End, Container>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename concatenateValueZipper <Type, front, middle, back> :: template type<Container>;
 };
}
#endif

