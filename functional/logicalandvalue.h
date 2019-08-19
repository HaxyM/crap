#ifndef CRAP_FUNCTIONAL_LOGICALANDVALUE
#define CRAP_FUNCTIONAL_LOGICALANDVALUE

namespace crap
{
 template <class Type, Type Value1, Type Value2> struct logicalAndValue
 {
  constexpr const static auto value = (Value1 && Value2);
 };
}
#endif

