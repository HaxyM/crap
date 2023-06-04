#ifndef CRAP_ALGORITHM_SEARCHALLTYPE
#define CRAP_ALGORITHM_SEARCHALLTYPE

#include "findalliftype.h"
#include "copyiffortype.h"
#include "../numeric.d/iotavalue.h"
#include "../numeric.d/outerproductfortype.h"
#include "../utility.d/typelist.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <template <class, class> class, class...> struct searchAllType;

 template <template <class, class> class Operator> struct searchAllType<Operator>
 {
  template <class ... Types> struct within;
 };

 template <template <class, class> class Operator, class PatternElement>
	 struct searchAllType<Operator, PatternElement>
 {
  template <class ... Types> struct within;
 };

 template <template <class, class> class Operator, class ... Pattern> struct searchAllType
 {
  template <class ... Types> struct within;
 };

 template <template <class, class> class Operator> template <class ... Types>
	 struct searchAllType <Operator> :: within
 {
  template <template <std :: size_t...> class Container = valueListForType <std :: size_t> :: template type>
	  using type = typename iotaValue <sizeof...(Types) + 1u, std :: size_t> :: template type<Container>;
 };

 template <template <class, class> class Operator, class PatternElement>
	 template <class ... Types> struct searchAllType <Operator, PatternElement> :: within
 {
  private:
  template <class Type> using isElement = Operator<Type, PatternElement>;
  public:
  template <template <std :: size_t...> class Container = valueListForType <std :: size_t> :: template type>
	  using type = typename findAllIfType <isElement, Types...> :: template type<Container>;
 };

 template <template <class, class> class Operator, class ... Pattern>
	 template <class ... Types> struct searchAllType <Operator, Pattern...> :: within
 {
  private:
  using pattern = typeList<Pattern...>;
  constexpr const static std :: size_t half = (pattern :: size) / 2u;
  template <class ... SubPattern>
	  using This = typename searchAllType <Operator, SubPattern...> :: template within<Types...>;
  template <std :: size_t lowerIndex, std :: size_t upperIndex>
	  using doesMatch = std :: integral_constant<std :: size_t, ((lowerIndex + half) == upperIndex) ? lowerIndex : sizeof...(Types)>;
  template <std :: size_t Index> using isIn = std :: integral_constant<bool, (Index != (sizeof...(Types)))>;
  using lower = typename pattern :: template till <half, This> :: template
	  type<outerProductForType <std :: size_t, doesMatch> :: template values>;
  using upper = typename pattern :: template since <half, This> :: template type<lower :: template with>;
  public:
  template <template <std :: size_t...> class Container = valueListForType <std :: size_t> :: template type>
	  using type = typename upper :: template
	  type <copyIfForType <std :: size_t, isIn> :: template values> :: template
	  type<Container>;
 };
}
#endif

