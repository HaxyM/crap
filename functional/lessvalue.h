#ifndef CRAP_FUNCTIONAL_LESSVALUE
#define CRAP_FUNCTIONAL_LESSVALUE

#include <type_traits>

namespace crap
{
 template <class Type, Type Value1, Type Value2> using lessValue = std :: integral_constant<bool, (Value1 < Value2)>;
}
#endif

