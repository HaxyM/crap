#ifndef CRAP_UTILITY_VALUEDEMULTIPLEXER
#define CRAP_UTILITY_VALUEDEMULTIPLEXER

namespace crap
{
 template <class Type, bool, template <template <Type...> class> class, template <Type...> class, template <Type...> class> struct valueDemultiplexer;

 template <class Type, template <template <Type...> class> class Source, template <Type...> class ContainerIfTrue, template <Type...> class ContainerIfFalse>
	 struct valueDemultiplexer<Type, true, Source, ContainerIfTrue, ContainerIfFalse>
 {
  using type = Source<ContainerIfTrue>;
 };

 template <class Type, bool, template <template <Type...> class> class Source, template <Type...> class, template <Type...> class ContainerIfFalse>
	 struct valueDemultiplexer
 {
  using type = Source<ContainerIfFalse>;
 };
}
#endif

