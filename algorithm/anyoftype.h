#ifndef CRAP_ALGORITHM_ANYOFTYPE
#define CRAP_ALGORITHM_ANYOFTYPE

#include "../functional/logicalorvalue.h"
#include "../utility/commontype.h"

namespace crap
{
 template <template <class> class Operator, class ... Types> struct anyOfType
 {
  private:
  using resultType = typename commonType <decltype(Operator <Types> :: value)...> :: type;
  public:
  constexpr const static auto value = logicalOrValue <resultType, static_cast<resultType>(Operator <Types> :: value)...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <template <class> class Operator, class ... Types>
inline constexpr crap :: anyOfType <Operator, Types...> :: operator typename crap :: anyOfType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: anyOfType <Operator, Types...> :: value;
}
#endif

