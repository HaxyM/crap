#ifndef CRAP_FUNCTIONAL_LOGICALNOTVALUE
#define CRAP_FUNCTIONAL_LOGICALNOTVALUE

#include <type_traits>

namespace crap
{
 template <class Type, Type Value> using logicalNotValue = std :: integral_constant<decltype(!Value), !Value>;
}
#endif

