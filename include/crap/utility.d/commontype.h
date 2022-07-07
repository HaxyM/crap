#ifndef CRAP_UTILITY_COMMONTYPE
#define CRAP_UTILITY_COMMONTYPE

#include "../numeric.d/reducetype.h"

#include <type_traits>

namespace crap
{
 template <class ... Types> using commonType = reduceType<std :: common_type, Types...>;
 template <class ... Types> using commonType_t = typename commonType <Types...> :: type;
}
#endif
