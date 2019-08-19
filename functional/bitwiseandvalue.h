#ifndef CRAP_FUNCTIONAL_BITWISEANDVALUE
#define CRAP_FUNCTIONAL_BITWISEANDVALUE

namespace crap
{
 template <class Type, Type Value1, Type Value2> struct bitwiseAndValue
 {
  constexpr const static auto value = (Value1 & Value2);
 };
}
#endif

