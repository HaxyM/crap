#ifndef CRAP_UTILITY_NULLTYPE
#define CRAP_UTILITY_NULLTYPE

#include "../algorithm/copytype.h"

namespace crap
{
 template <class...> using nullType = copyType<>;
}
#endif
