#ifndef CRAP_ALGORITHM_FINDALLIFTYPE
#define CRAP_ALGORITHM_FINDALLIFTYPE

#include "copyvalue.h"
#include "../utility.d/typelist.h"
#include "../utility.d/nullvalue.h"
#include "../utility.d/valuelistfortype.h"
#include "../utility.d/valuemultiplexer.h"

#include <cstddef>

namespace crap
{
 template <template <class> class, class...> struct findAllIfType;

 template <template <class> class Operator> struct findAllIfType<Operator>
	 : nullValue<std :: size_t> {};

 template <template <class> class Operator, class Type> struct findAllIfType<Operator, Type>
 {
  private:
  template <template <std :: size_t...> class Container> using ifTrue = Container<0u>;
  template <template <std :: size_t...> class Container> using ifNot = Container<>;
  public:
  template <template <std :: size_t...> class Container = valueListForType <std :: size_t> :: template type>
	  using type = typename valueMultiplexer <std :: size_t, Operator <Type> :: value, Container, ifTrue, ifNot> :: type;
 };

 template <template <class> class Operator, class ... Types> struct findAllIfType
 {
  private:
  using types = typeList<Types...>;
  constexpr const static std :: size_t half = (types :: size) / 2u;
  template <class ... SubTypes> using This = findAllIfType<Operator, SubTypes...>;
  template <template <std :: size_t...> class Container>
	  using lower = typename types :: template till <half, This> :: template type<Container>;
  template <template <std :: size_t...> class Container>
	  using upper = typename types :: template since <half, This> :: template type<Container>;
  template <std :: size_t ... Indices1> struct merge;
  public:
  template <template <std :: size_t...> class Container = valueListForType <std :: size_t> :: template type>
	  using type = typename upper <lower <merge> :: template with> :: template type<Container>;
 };

 template <template <class> class Operator, class ... Types> template <std :: size_t ... Indices1>
	 struct findAllIfType <Operator, Types...> :: merge
 {
  template <std :: size_t ... Indices2>
	  using with = copyValue<std :: size_t, Indices1..., ((sizeof...(Types) / 2u) + Indices2)...>;
 };
}
#endif

