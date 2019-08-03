#ifndef CRAP_ALGORITHM_FILL
#define CRAP_ALGORITHM_FILL

#include <utility>

#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, std :: size_t N, Type Value> struct fillValue
 {
  private:
  template <template <Type...> class Container> struct generator;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
  using type = decltype(generator <Container> :: generate(std :: make_index_sequence<N>{}));
 };

 template <class Type, std :: size_t N, Type Value> template <template <Type...> class Container> struct fillValue <Type, N, Value> :: generator
 {
  template <std :: size_t Index> constexpr const static Type valueAt = Value;
  template <std :: size_t ... Indices> static Container<valueAt<Indices>...> generate(std :: index_sequence<Indices...>);
 };
}
#endif

