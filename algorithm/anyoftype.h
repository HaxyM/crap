#ifndef CRAP_ALGORITHM_ANYOFTYPE
#define CRAP_ALGORITHM_ANYOFTYPE

#include "../functional/logicalorvalue.h"

#include <type_traits>

namespace crap
{
 template <template <class> class Operator, class ... Types> struct anyOfType
 {
  private:
  using resultType = std :: common_type_t<decltype(Operator <Types> :: value)...>;
  public:
  constexpr const static auto value = logicalOrValue <resultType, static_cast<resultType>(Operator <Types> :: value)...> :: value;
 };
}
#endif

