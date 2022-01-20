#ifndef CRAP_FUNCTIONAL_NEGATEVALUE
#define CRAP_FUNCTIONAL_NEGATEVALUE

#include <type_traits>

namespace crap
{
 template <class Type, Type Value> using negateValue = std :: integral_constant<decltype(-Value), -Value>;
}
#endif

