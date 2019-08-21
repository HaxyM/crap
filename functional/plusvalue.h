#ifndef CRAP_FUNCTIONAL_PLUSVALUE
#define CRAP_FUNCTIONAL_PLUSVALUE

namespace crap
{
 template <class Type, Type Value1, Type Value2> struct plusValue
 {
  constexpr const static auto value = (Value1 + Value2);
 };
}
#endif

