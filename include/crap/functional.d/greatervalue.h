#ifndef CRAP_FUNCTIONAL_GREATERVALUE
#define CRAP_FUNCTIONAL_GREATERVALUE

#include <type_traits>

namespace crap
{
 template <class Type, Type Value1, Type Value2> using greaterValue = std :: integral_constant<bool, (Value1 > Value2)>;
}
#endif

