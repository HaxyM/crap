#ifndef CRAP_ALGORITHM_SEARCHALLVALUE
#define CRAP_ALGORITHM_SEARCHALLVALUE

#include "findallifvalue.h"
#include "copyiffortype.h"
#include "../numeric.d/iotavalue.h"
#include "../numeric.d/outerproductfortype.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct searchAllValue;

 template <class Type, template <Type, Type> class Operator> struct searchAllValue<Type, Operator>
 {
  template <Type ... Values> struct within;
 };

 template <class Type, template <Type, Type> class Operator, Type PatternElement>
	 struct searchAllValue<Type, Operator, PatternElement>
 {
  template <Type ... Values> struct within;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Pattern> struct searchAllValue
 {
  template <Type ... Values> struct within;
 };

 template <class Type, template <Type, Type> class Operator> template <Type ... Values>
	 struct searchAllValue <Type, Operator> :: within
 {
  template <template <std :: size_t...> class Container = valueListForType <std :: size_t> :: template type>
	  using type = typename iotaValue <sizeof...(Values) + 1u, std :: size_t> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type PatternElement>
	 template <Type ... Values> struct searchAllValue <Type, Operator, PatternElement> :: within
 {
  private:
  template <Type Value> using isElement = Operator<Value, PatternElement>;
  public:
  template <template <std :: size_t...> class Container = valueListForType <std :: size_t> :: template type>
	  using type = typename findAllIfValue <Type, isElement, Values...> :: template type<Container>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Pattern>
	 template <Type ... Values> struct searchAllValue <Type, Operator, Pattern...> :: within
 {
  private:
  using pattern = valueList<Type, Pattern...>;
  constexpr const static std :: size_t half = (pattern :: size) / 2u;
  template <Type ... SubPattern>
	  using This = typename searchAllValue <Type, Operator, SubPattern...> :: template within<Values...>;
  template <std :: size_t lowerIndex, std :: size_t upperIndex>
	  using doesMatch = std :: integral_constant<std :: size_t, ((lowerIndex + half) == upperIndex) ? lowerIndex : sizeof...(Values)>;
  template <std :: size_t Index> using isIn = std :: integral_constant<bool, (Index != (sizeof...(Values)))>;
  using lower = typename pattern :: template till <half, This> :: template type<outerProductForType <std :: size_t, doesMatch> :: template values>;
  using upper = typename pattern :: template since <half, This> :: template type<lower :: template with>;
  public:
  template <template <std :: size_t...> class Container = valueListForType <std :: size_t> :: template type>
	  using type = typename upper :: template type <copyIfForType <std :: size_t, isIn> :: template values> :: template type<Container>;
 };
}
#endif

