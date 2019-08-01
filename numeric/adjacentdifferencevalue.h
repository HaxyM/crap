#ifndef CRAP_NUMERIC_ADJACENTDIFFERENCEVALUE
#define CRAP_NUMERIC_ADJACENTDIFFERENCEVALUE

#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct adjacentDifferenceValue;

 template <class Type, template <Type, Type> class Operator> struct adjacentDifferenceValue<Type, Operator>
 {
  using type = valueList<Type>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct adjacentDifferenceValue
 {
  private:
  template <template <Type...> class Container> struct Implementation;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
  using type = decltype(Implementation <Container> :: generate(std :: make_index_sequence<(Implementation <Container> :: values :: size) - 1u>{}));
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
 template <template <Type...> class Container> struct adjacentDifferenceValue <Type, Operator, Values...> :: Implementation
 {
  using values = valueList<Type, Values...>;
  template <std :: size_t Index> using valueAt = Operator<values :: template at<Index + 1u>, values :: template at<Index> >;
  template <std :: size_t ... Indices> static Container<values :: template at<0u>, valueAt <Indices> :: value...>
  generate(std :: index_sequence<Indices...>);
 };
}
#endif

