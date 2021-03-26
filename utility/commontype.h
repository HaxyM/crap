#ifndef CRAP_UTILITY_COMMONTYPE
#define CRAP_UTILITY_COMMONTYPE

#include "../numeric/reducetype.h"

#include <type_traits>

namespace crap
{
 template <class ... Types> using commonType = reduceType<std :: common_type, Types...>;
}
#endif
