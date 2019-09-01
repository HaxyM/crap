#ifndef CRAP_UTILITY_VALUEMULTIPLEXER
#define CRAP_UTILITY_VALUEMULTIPLEXER

namespace crap
{
 template <class Type, bool, template <Type...> class, template <template <Type...> class> class, template <template <Type...> class> class>
	 struct valueMultiplexer;
 template <class Type, template <Type...> class Container, template <template <Type...> class> class SourceIfTrue, template <template <Type...> class> class SourceIfFalse>
	 struct valueMultiplexer<Type, true, Container, SourceIfTrue, SourceIfFalse>
 {
  using type = SourceIfTrue<Container>;
 };

 template <class Type, bool, template <Type...> class Container, template <template <Type...> class> class, template <template <Type...> class> class SourceIfFalse>
	 struct valueMultiplexer
 {
  using type = SourceIfFalse<Container>;
 };
}
#endif

