#ifndef CRAP_FUNCTIONAL_LOGICALORVALUE
#define CRAP_FUNCTIONAL_LOGICALORVALUE

namespace crap
{
 template <class Type, Type Value1, Type Value2> struct logicalOrValue
 {
  constexpr const static auto value = (Value1 || Value2);
 };
}
#endif

