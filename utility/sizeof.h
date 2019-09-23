#ifndef CRAP_UTILITY_SIZEOF
#define CRAP_UTILITY_SIZEOF

#include <utility>

namespace crap
{
 template <class Type> using sizeOf = std :: integral_constant<std :: size_t, sizeof(Type)>;
}
#endif

