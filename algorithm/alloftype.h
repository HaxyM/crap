#ifndef CRAP_ALGORITHM_ALLOFTYPE
#define CRAP_ALGORITHM_ALLOFTYPE

#include "../functional/logicalandvalue.h"

#include <type_traits>

namespace crap
{
 template <template <class> class Operator, class ... Types> struct allOfType
 {
  private:
  using resultType = std :: common_type_t<decltype(Operator <Types> :: value)...>;
  public:
  constexpr const static auto value = logicalAndValue <resultType, static_cast<resultType>(Operator <Types> :: value)...> :: value;
 };
}
#endif

