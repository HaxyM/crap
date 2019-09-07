#ifndef CRAP_FUNCTIONAL_NEGATEVALUE
#define CRAP_FUNCTIONAL_NEGATEVALUE

namespace crap
{
 template <class Type, Type Value> struct negateValue
 {
  constexpr const static auto value = -Value;
 };
}
#endif

