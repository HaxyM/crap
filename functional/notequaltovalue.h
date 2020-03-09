#ifndef CRAP_FUNCTIONAL_NOTEQUALTOVALUE
#define CRAP_FUNCTIONAL_NOTEQUALTOVALUE

#include <type_traits>

namespace crap
{
 template <class Type, Type Value1, Type Value2> using notEqualToValue = std :: integral_constant<bool, (Value1 != Value2)>;
}
#endif

