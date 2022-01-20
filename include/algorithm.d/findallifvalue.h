#ifndef CRAP_ALGORITHM_FINDALLIFVALUE
#define CRAP_ALGORITHM_FINDALLIFVALUE

#include "../utility.d/valuelistfortype.h"
#include "../utility.d/valuemultiplexer.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct findAllIfValue;

 template <class Type, template <Type> class Operator> struct findAllIfValue<Type, Operator>
 {
  template <template <std :: size_t...> class Container = valueListForType <std :: size_t> :: template type>
	  using type = Container<>;
 };

 template <class Type, template <Type> class Operator, Type Value> struct findAllIfValue<Type, Operator, Value>
 {
  private:
  template <template <std :: size_t...> class Container> using PassedSource = Container<0u>;
  template <template <std :: size_t...> class Container> using FailedSource = Container<>;
  constexpr const static bool passed = Operator <Value> :: value;
  public:
  template <template <std :: size_t...> class Container = valueListForType <std :: size_t> :: template type>
	  using type = typename valueMultiplexer <std :: size_t, passed, Container, PassedSource, FailedSource> :: type;
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct findAllIfValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  template <std :: size_t Half, std :: size_t ... LowerIndices> struct specialMerger;
  template <std :: size_t ... LowerIndices> using merger = specialMerger<half, LowerIndices...>;
  template <Type ... SubValues> using This = findAllIfValue<Type, Operator, SubValues...>;
  using lower = typename values :: template till <half, This> :: template type<merger>;
  using upper = typename values :: template since <half, This> :: template type<lower :: template with>;
  public:
  template <template <std :: size_t...> class Container = valueListForType <std :: size_t> :: template type>
	  using type = typename upper :: template type<Container>;
 };

 template <class Type, template <Type> class Operator, Type ... Values>
	 template <std :: size_t Half, std :: size_t ... LowerIndices>
	 struct findAllIfValue <Type, Operator, Values...> :: specialMerger
 {
  template <std :: size_t ... UpperIndices> struct with;
 };

 template <class Type, template <Type> class Operator, Type ... Values>
	 template <std :: size_t Half, std :: size_t ... LowerIndices>
	 template <std :: size_t ... UpperIndices>
	 struct findAllIfValue <Type, Operator, Values...> :: template specialMerger <Half, LowerIndices...> :: with
 {
  template <template <std :: size_t...> class Container> using type = Container<LowerIndices..., (Half + UpperIndices)...>;
 };
}
#endif

