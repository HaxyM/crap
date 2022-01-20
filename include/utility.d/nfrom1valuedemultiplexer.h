#ifndef CRAP_UTILITY_NFROM1VALUEDEMULTIPLEXER
#define CRAP_UTILITY_NFROM1VALUEDEMULTIPLEXER

#include "valuecontainerlist.h"

namespace crap
{
 template <class Type, std :: size_t N, template <template <Type...> class> class Source, template <Type...> class ... Containers>
	 struct Nfrom1ValueDemultiplexer
 {
  using type = Source<valueContainerList <Type, Containers...> :: template At <N> :: template type>;
 };
}
#endif

