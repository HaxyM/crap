#ifndef CRAP_ALGORITHM_MERGESORTTYPE
#define CRAP_ALGORITHM_MERGESORTTYPE

#include "copytype.h"
#include "mergetypezipper.h"

namespace crap
{
 template <template <class, class> class Operator, class ... Types>
	 using mergeSortType = mergeTypeZipper<Operator, copyType <Types> :: template type...>;
}
#endif

