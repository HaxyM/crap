#ifndef CRAP_FUNCTIONAL_EQUALTOVALUE
#define CRAP_FUNCTIONAL_EQUALTOVALUE

#include <type_traits>

namespace crap
{
 template <class Type, Type Value1, Type Value2> using equalToValue = std :: integral_constant<bool, (Value1 == Value2)>;
}
#endif

