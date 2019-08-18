#ifndef CRAP_FUNCTIONAL_LESSEQUALVALUE
#define CRAP_FUNCTIONAL_LESSEQUALVALUE

namespace crap
{
 template <class Type, Type Value1, Type Value2> struct lessEqualValue
 {
  constexpr const static bool value = (Value1 <= Value2);
 };
}
#endif

