#ifndef CRAP_UTILITY_NTO1VALUEMULTIPLEXER
#define CRAP_UTILITY_NTO1VALUEMULTIPLEXER

#include "valuesourcelist.h"

namespace crap
{
 template <class Type, std :: size_t N, template <Type...> class Container, template <template <Type...> class> class ... Sources>
	 struct Nto1ValueMultiplexer
 {
  using type = typename valueSourceList <Type, Sources...> :: template At <N> :: template type<Container>;
 };
}
#endif

