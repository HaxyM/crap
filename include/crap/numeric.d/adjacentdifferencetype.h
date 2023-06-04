#ifndef CRAP_NUMERIC_ADJACENTDIFFERENCETYPE
#define CRAP_NUMERIC_ADJACENTDIFFERENCETYPE

#include "../utility.d/makeindexsequence.h"
#include "../utility.d/typelist.h"

namespace crap
{
 template <template <class, class> class, class...> struct adjacentDifferenceType;

 template <template <class, class> class Operator> struct adjacentDifferenceValue<Operator>
 {
  template <template <class...> class Container = typeList> using type = Container<>;
 };

 template <template <class, class> class Operator, class ... Types> struct adjacentDifferenceType
 {
  private:
  template <template <class...> class Container> struct Implementation;
  public:
  template <template <class...> class Container = typeList>
  using type = decltype(Implementation <Container> :: generate(makeIndexSequence<(Implementation <Container> :: types :: size) - 1u>{}));
 };

 template <template <class, class> class Operator, class ... Types>
 template <template <class...> class Container> struct adjacentDifferenceType <Operator, Types...> :: Implementation
 {
  using types = typeList<Types...>;
  template <std :: size_t Index> using typeAt = Operator<typename types :: template at<Index + 1u>, typename types :: template at<Index>>;
  template <std :: size_t ... Indices> static Container<typename types :: template at<0u>, typeAt <Indices> :: type...>
  generate(indexSequence<Indices...>);
 };
}
#endif

