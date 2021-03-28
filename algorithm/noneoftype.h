#ifndef CRAP_ALGORITHM_NONEOFTYPE
#define CRAP_ALGORITHM_NONEOFTYPE

#include "../functional/logicalnotvalue.h"
#include "../functional/logicalorvalue.h"
#include "../utility/commontype.h"

namespace crap
{
 template <template <class> class Operator, class ... Types> struct noneOfType
 {
  private:
  using resultType = typename commonType <decltype(Operator <Types> :: value)...> :: type;
  constexpr const static auto orValue = logicalOrValue <resultType, static_cast<resultType>(Operator <Types> :: value)...> :: value;
  public:
  constexpr const static auto value = logicalNotValue <decltype(orValue), orValue> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <template <class> class Operator, class ... Types>
inline constexpr crap :: noneOfType <Operator, Types...> :: operator typename crap :: noneOfType <Operator, Types...> :: value_type () const noexcept
{
 return crap :: noneOfType <Operator, Types...> :: value;
}
#endif
