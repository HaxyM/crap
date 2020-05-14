#ifndef CRAP_UTILITY_NULLVALUE
#define CRAP_UTILITY_NULLVALUE

#include "../algorithm/copyvalue.h"

namespace crap
{
 template <class Type, Type...> using nullValue = copyValue<Type>;
}
#endif

