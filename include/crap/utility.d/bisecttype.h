#ifndef CRAP_UTILITY_BISECTTYPE
#define CRAP_UTILITY_BISECTTYPE

#include "splittype.h"

namespace crap
{
 template <class ... Types> using bisectType = splitType<(sizeof...(Types) / 2u), Types...>;
}
#endif

