#ifndef CRAP_UTILITY_TYPEMULTIPLEXER
#define CRAP_UTILITY_TYPEMULTIPLEXER

namespace crap
{
 template <bool, template <class...> class, template <template <class...> class> class, template <template <class...> class> class>
	 struct typeMultiplexer;
  
 template <template <class...> class Container, template <template <class...> class> class SourceIfTrue, template <template <class...> class> class SourceIfFalse>
	 struct typeMultiplexer<true, Container, SourceIfTrue, SourceIfFalse>
 {
  using type = SourceIfTrue<Container>;
 };

 template <bool, template <class...> class Container, template <template <class...> class> class, template <template <class...> class> class SourceIfFalse>
	 struct typeMultiplexer
 {
  using type = SourceIfFalse<Container>;
 };
}
#endif
