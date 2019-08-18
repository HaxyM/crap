#ifndef CRAP_FUNCTIONAL_NOTEQUALTOVALUE
#define CRAP_FUNCTIONAL_NOTEQUALTOVALUE

namespace crap
{
 template <class Type, Type Value1, Type Value2> struct notEqualToValue
 {
  constexpr const static bool value = (Value1 != Value2);
 };
}
#endif

