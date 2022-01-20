#ifndef CRAP_FUNCTIONAL_BITWISENOTVALUE
#define CRAP_FUNCTIONAL_BITWISENOTVALUE

#include <type_traits>

namespace crap
{
 template <class Type, Type Value> using bitwiseNotValue = std :: integral_constant<decltype(~Value), ~Value>;
}
#endif

