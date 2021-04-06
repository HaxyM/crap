#ifndef CRAP_ALGORITHM_ALLOFTYPE
#define CRAP_ALGORITHM_ALLOFTYPE

#include "../functional/logicalandvalue.h"
#include "../utility/commontype.h"

namespace crap
{
 template <template <class> class Operator, class ... Types> struct allOfType
 {
  private:
  using resultType = typename commonType <decltype(Operator <Types> :: value)...> :: type;
  public:
  constexpr const static auto value = logicalAndValue <resultType, static_cast<resultType>(Operator <Types> :: value)...> :: value;
  using value_type = decltype(value);
  constexpr operator value_type () const noexcept;
 };
}

template <template <class> class Operator, class ... Types>
inline constexpr crap :: allOfType <Operator, Types...> :: operator typename crap :: allOfType <Operator, Types...> :: value_type () const noexcept
{
 return value;
}
#endif

