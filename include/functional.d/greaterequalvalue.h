#ifndef CRAP_FUNCTIONAL_GREATEREQUALVALUE
#define CRAP_FUNCTIONAL_GREATEREQUALVALUE

#include <type_traits>

namespace crap
{
 template <class Type, Type Value1, Type Value2> using greaterEqualValue = std :: integral_constant<bool, (Value1 >= Value2)>;
}
#endif

