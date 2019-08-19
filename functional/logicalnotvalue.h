#ifndef CRAP_FUNCTIONAL_LOGICALNOTVALUE
#define CRAP_FUNCTIONAL_LOGICALNOTVALUE

namespace crap
{
 template <class Type, Type Value> struct logicalNotValue
 {
  constexpr const static auto value = !Value;
 };
}
#endif

