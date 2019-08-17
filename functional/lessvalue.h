#ifndef CRAP_FUNCTIONAL_LESSVALUE
#define CRAP_FUNCTIONAL_LESSVALUE

namespace crap
{
 template <class Type, Type Value1, Type Value2> struct lessValue
 {
  constexpr const static bool value = (Value1 < Value2);
 };
}
#endif

