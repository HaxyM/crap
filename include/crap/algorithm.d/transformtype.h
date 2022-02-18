#ifndef CRAP_ALGORITHM_TRANSFORMTYPE
#define CRAP_ALGORITHM_TRANSFORMTYPE

#include "copytype.h"

namespace crap
{
 template <template <class> class Operator, class ... Types>
	 using transformType = copyType<typename Operator <Types> :: type...>;
}
#endif

