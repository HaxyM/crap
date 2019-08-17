#ifndef CRAP_FUNCTIONAL_EQUALTOVALUE
#define CRAP_FUNCTIONAL_EQUALTOVALUE

namespace crap
{
 template <class Type, Type Value1, Type Value2> struct equalToValue
 {
  constexpr const static bool value = (Value1 == Value2);
 };
}
#endif

