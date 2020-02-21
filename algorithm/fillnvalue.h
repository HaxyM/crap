#ifndef CRAP_ALGORITHM_FILLNVALUE
#define CRAP_ALGORITHM_FILLNVALUE

#include <utility>

#include "../utility/makeindexsequence.h"
#include "../utility/valuecontaineridentity.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, std :: size_t N, Type Value> struct fillNValue
 {
  #if defined(__clang__)
  private:
  template <template <Type...> class Container> struct generator;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename generator <Container> :: type;
  #else
  private:
  template <template <Type...> class Container, std :: size_t ... Indices>
	  static Container<(Indices, Value)...> generate(valueContainerIdentity<Type, Container>, indexSequence<Indices...>);
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = decltype(generate(valueContainerIdentity<Type, Container>{}, makeIndexSequence<N>{}));
  #endif
 };

 #if defined(__clang__)
 template <class Type, std :: size_t N, Type Value>
	 template <template <Type...> class Container>
 struct fillNValue <Type, N, Value> :: generator
 {
  template <std :: size_t ... Indices> static Container<(Indices,Value)...>
	  generate(indexSequence<Indices...>);
  using type = decltype(generate(makeIndexSequence<N>{}));
 };
 #endif
}
#endif

