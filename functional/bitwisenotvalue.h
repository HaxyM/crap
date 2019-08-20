#ifndef CRAP_FUNCTIONAL_BITWISENOTVALUE
#define CRAP_FUNCTIONAL_BITWISENOTVALUE

namespace crap
{
 template <class Type, Type Value> struct bitwiseNotValue
 {
  constexpr const static auto value = ~Value;
 };
}
#endif

