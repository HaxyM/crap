#ifndef CRAP_FUNCTIONAL_GREATERVALUE
#define CRAP_FUNCTIONAL_GREATERVALUE

namespace crap
{
 template <class Type, Type Value1, Type Value2> struct greaterValue
 {
  constexpr const static bool value = (Value1 > Value2);
 };
}
#endif

