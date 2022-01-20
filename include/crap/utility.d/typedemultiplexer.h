  
#ifndef CRAP_UTILITY_TYPEDEMULTIPLEXER
#define CRAP_UTILITY_TYPEDEMULTIPLEXER

namespace crap
{
 template <bool, template <template <class...> class> class, template <class...> class, template <class...> class> struct typeDemultiplexer;

 template <template <template <class...> class> class Source, template <class...> class ContainerIfTrue, template <class...> class ContainerIfFalse>
	 struct typeDemultiplexer<true, Source, ContainerIfTrue, ContainerIfFalse>
 {
  using type = Source<ContainerIfTrue>;
 };

 template <bool, template <template <class...> class> class Source, template <class...> class, template <class...> class ContainerIfFalse>
	 struct typeDemultiplexer
 {
  using type = Source<ContainerIfFalse>;
 };
}
#endif
