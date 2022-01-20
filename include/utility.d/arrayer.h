#ifndef CRAP_UTILITY_ARRAYER
#define CRAP_UTILITY_ARRAYER

#include <array>

namespace crap
{
 template <class Type, Type ... Values> class arrayer
 {
  public:
  using type = Type;
  constexpr const static std :: array<Type, sizeof...(Values)> array();
 };

 template <class Type> struct arrayerForType
 {
  template <Type ... Values> using type = arrayer<Type, Values...>;
 };
}

template <class Type, Type ... Values> constexpr const std :: array<Type, sizeof...(Values)> crap :: arrayer <Type, Values...> :: array()
{
 return {Values...};
}
#endif

