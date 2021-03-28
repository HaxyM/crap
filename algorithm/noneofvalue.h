#ifndef CRAP_ALGORITHM_NONEOFVALUE
#define CRAP_ALGORITHM_NONEOFVALUE

#include "../functional/logicalnotvalue.h"
#include "../functional/logicalorvalue.h"
#include "../utility/commontype.h"

namespace crap
{
 template <class Type, template <Type> class Operator, Type ... Values> struct noneOfValue
 {
  private:
  using resultType = typename commonType <decltype(Operator <Values> :: value)...> :: type;
  constexpr const static auto orValue = logicalOrValue <resultType, static_cast<resultType>(Operator <Values> :: value)...> :: value;
  public:
  constexpr const static auto value = logicalNotValue <decltype(orValue), orValue> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <class Type, template <Type> class Operator, Type ... Values>
inline constexpr crap :: noneOfValue <Type, Operator, Values...> :: operator typename crap :: noneOfValue <Type, Operator, Values...> :: value_type () const noexcept
{
 return crap :: noneOfValue <Type, Operator, Values...> :: value;
}
#endif
