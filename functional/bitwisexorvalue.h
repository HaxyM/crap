#ifndef CRAP_FUNCTIONAL_BITWISEXORVALUE
#define CRAP_FUNCTIONAL_BITWISEXORVALUE

namespace crap
{
 template <class Type, Type Value1, Type Value2> struct bitwiseXorValue
 {
  constexpr const static auto value = (Value1 ^ Value2);
 };
}
#endif

