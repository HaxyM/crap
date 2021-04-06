#ifndef CRAP_ALGORITHM_ANYOFVALUE
#define CRAP_ALGORITHM_ANYOFVALUE

#include "../functional/logicalorvalue.h"
#include "../utility/commontype.h"

#include <type_traits>

namespace crap
{
 template <class Type, template <Type> class Operator, Type ... Values> struct anyOfValue
 {
  private:
  using resultType = typename commonType <decltype(Operator <Values> :: value)...> :: type;
  public:
  constexpr const static auto value = logicalOrValue <resultType, static_cast<resultType>(Operator <Values> :: value)...> :: value;
 };
}
#endif

