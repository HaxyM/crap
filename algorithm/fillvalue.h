#ifndef CRAP_ALGORITHM_FILLVALUE
#define CRAP_ALGORITHM_FILLVALUE

#include <utility>

#include "../utility/makeindexsequence.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, std :: size_t N, Type Value> struct fillValue
 {
  private:
  template <template <Type...> class Container> struct generator;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = decltype(generator <Container> :: generate(makeIndexSequence<N>{}));
 };

 template <class Type, std :: size_t N, Type Value> template <template <Type...> class Container> struct fillValue <Type, N, Value> :: generator
 {
  template <std :: size_t ... Indices> static Container<(Indices, Value)...> generate(indexSequence<Indices...>);
 };
}
#endif

