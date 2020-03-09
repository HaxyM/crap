#ifndef CRAP_FUNCTIONAL_LESSEQUALVALUE
#define CRAP_FUNCTIONAL_LESSEQUALVALUE

#include <type_traits>

namespace crap
{
 template <class Type, Type Value1, Type Value2> using lessEqualValue = std :: integral_constant<bool, (Value1 <= Value2)>;
}
#endif

