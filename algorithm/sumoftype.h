#ifndef CRAP_ALGORITHM_SUMOFTYPE
#define CRAP_ALGORITHM_SUMOFTYPE

#include "../functional/plusvalue.h"



#include <type_traits>

namespace crap
{
 template <template <class> class Operator, class ... Types> struct sumOfType
 {
  private:
  using resultType = typename std :: common_type <decltype(Operator <Types> :: value)...> :: type;
  public:
  constexpr const static auto value = plusValue <resultType, static_cast<resultType>(Operator <Types> :: value)...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <template <class> class Operator, class ... Types>
inline constexpr crap :: sumOfType <Operator, Types...> :: operator typename crap :: sumOfType <Operator, Types...> :: value_type () const noexcept
{
 return value;
}
#endif

