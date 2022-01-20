#ifndef CRAP_ALGORITHM_SETSYMMETRICDIFFERENCEVALUE
#define CRAP_ALGORITHM_SETSYMMETRICDIFFERENCEVALUE

#include "copyvalue.h"
#include "equalrangevalue.h"
#include "mergevalue.h"
#include "../utility.d/concatenatevaluezipper.h"
#include "../utility.d/erasevalue.h"
#include "../utility.d/valuedemultiplexer.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct setSymmetricDifferenceValue;

 template <class Type, template <Type, Type> class Operator> struct setSymmetricDifferenceValue<Type, Operator>
 {
  template <Type ... Values2> using with = copyValue<Type, Values2...>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> struct setSymmetricDifferenceValue<Type, Operator, Value1>
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> struct setSymmetricDifferenceValue
 {
  template <Type ... Values2> struct with;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1> template <Type ... Values2>
	 struct setSymmetricDifferenceValue <Type, Operator, Value1> :: with
 {
  private:
  using range = equalRangeValue<Type, Value1, Operator, Values2...>;
  constexpr const static bool has = ((range :: begin) != (range :: end));
  constexpr const static std :: size_t newEnd = (range :: begin) + 1u;
  template <Type ... Values> using removingContainer = eraseValue<Type, (range :: begin), newEnd, Values...>;
  template <Type ... Values> using mergingContainer = typename mergeValue <Type, Operator, Value1> :: template with<Values...>;
  using result = typename valueDemultiplexer <Type, has, copyValue <Type, Values2...> :: template type, removingContainer, mergingContainer> :: type;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename result :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> template <Type ... Values2>
	 struct setSymmetricDifferenceValue <Type, Operator, Values1...> :: with
 {
  private:
  using values1 = valueList<Type, Values1...>;
  using values2 = valueList<Type, Values2...>;
  constexpr const static Type midValue = values1 :: template At <(values1 :: size) / 2u> :: value;
  using range1 = equalRangeValue<Type, midValue, Operator, Values1...>;
  using range2 = equalRangeValue<Type, midValue, Operator, Values2...>;
  constexpr const static std :: size_t range1Size = ((range1 :: end) - (range1 :: begin));
  constexpr const static std :: size_t range2Size = ((range2 :: end) - (range2 :: begin));
  constexpr const static std :: size_t range1ShiftedBegin = ((range1 :: begin) + range2Size);
  constexpr const static std :: size_t range2ShiftedBegin = ((range2 :: begin) + range1Size);
  constexpr const static std :: size_t range1Begin = ((range1ShiftedBegin < (range1 :: end)) ? range1ShiftedBegin : (range1 :: end));
  constexpr const static std :: size_t range2Begin = ((range2ShiftedBegin < (range2 :: end)) ? range2ShiftedBegin : (range2 :: end));
  template <Type ... SubValues> using This = setSymmetricDifferenceValue<Type, Operator, SubValues...>;
  template <template <Type...> class Container> using midRange1 = typename values1 :: template subRange <range1Begin, (range1 :: end), Container>;
  template <template <Type...> class Container> using midRange2 = typename values2 :: template subRange <range2Begin, (range2 :: end), Container>;
  template <template <Type...> class Container>
	  using lower = typename values2 :: template
	  till <(range2 :: begin), values1 :: template till <(range1 :: begin), This> :: template with> :: template type<Container>;
  template <template <Type...> class Container>
	  using upper = typename values2 :: template
	  since <(range2 :: end), values1 :: template since <(range1 :: end), This> :: template with> :: template type<Container>;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename concatenateValueZipper <Type, lower, midRange1, midRange2, upper> :: template type<Container>;
 };
}
#endif

