#ifndef CRAP_UTILITY_REPRODUCEVALUE
#define CRAP_UTILITY_REPRODUCEVALUE

#include <cstddef>

#include "../numeric.d/iotavalue.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <std :: size_t N, class Type, Type Value> struct reproduceValue
 {
  private:
  template <template <Type...> class Contianler> struct Implementation;
  public:
  template <template <Type...> class Container = valueListForType <Type> :: template type>
	  using type = typename Implementation <Container> :: type;
 };

 template <std :: size_t N, class Type, Type Value> template <template <Type...> class Container>
	 struct reproduceValue <N, Type, Value> :: Implementation
 {
  private:
  template <std :: size_t ... Indices> using transformer = Container<(Indices, Value)...>;
  public:
  using type = typename iotaValue <N, std :: size_t> :: template type<transformer>;
 };
}
#endif

