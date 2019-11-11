#ifndef CRAP_ALGORITHM_MERGESORTVALUE
#define CRAP_ALGORITHM_MERGESORTVALUE

#include "mergevaluezipper.h"
#include "../utility/makeindexsequence.h"
#include "../utility/valuelist.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct mergeSortValue;
 
 template <class Type, template <Type, Type> class Operator> struct mergeSortValue<Type, Operator>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
 	 using type = Container<>;
 };
 
 template <class Type, template <Type, Type> class Operator, Type Value> struct mergeSortValue<Type, Operator, Value>
 {
  template <template <Type...> class Container = valueListForType <Type> :: template type>
 	 using type = Container<Value>;
 };
 
 template <class Type, template <Type, Type> class Operator, Type ... Values> struct mergeSortValue
 {
  private:
  template <std :: size_t Index> struct elementSource;
  template <std :: size_t ... Indices>
 	 static mergeValueZipper<Type, Operator, elementSource <Indices> :: template type...>
 	 getZipper(indexSequence<Indices...>);
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
 	 using type = typename decltype(getZipper(makeIndexSequence<sizeof...(Values)>{})) :: template type<Container>;
 };
 
 template <class Type, template <Type, Type> class Operator, Type ... Values> template <std :: size_t Index>
 struct mergeSortValue <Type, Operator, Values...> :: elementSource
 {
  private:
  using values = valueList<Type, Values...>;
  public:
  template <template <Type...> class Container> using type = Container<values :: template At <Index> :: value>;
 };
}
#endif

