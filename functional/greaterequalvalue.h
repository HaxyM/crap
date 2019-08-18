#ifndef CRAP_FUNCTIONAL_GREATEREQUALVALUE
#define CRAP_FUNCTIONAL_GREATEREQUALVALUE

namespace crap
{
 template <class Type, Type Value1, Type Value2> struct greaterEqualValue
 {
  constexpr const static bool value = (Value1 >= Value2);
 };
}
#endif

