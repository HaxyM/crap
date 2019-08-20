#ifndef CRAP_FUNCTIONAL_BITWISEORVALUE
#define CRAP_FUNCTIONAL_BITWISEORVALUE

namespace crap
{
 template <class Type, Type Value1, Type Value2> struct bitwiseOrValue
 {
  constexpr const static auto value = (Value1 | Value2);
 };
}
#endif

