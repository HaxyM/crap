#ifndef CRAP_UTILITY_INTEGRALCONSTANTFORTYPE
#define CRAP_UTILITY_INTEGRALCONSTANTFORTYPE

#include <type_traits>

namespace crap
{
 template <class Type> struct integralConstantForType
 {
  template <Type Value> using type = std :: integral_constant<Type, Value>;
 };
}
#endif

