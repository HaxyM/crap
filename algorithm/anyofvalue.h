#ifndef CRAP_ALGORITHM_ANYOFVALUE
#define CRAP_ALGORITHM_ANYOFVALUE

#include "../functional/logicaloperatorsfortype.h"

#include <type_traits>

namespace crap
{
 template <class Type, template <Type> class Operator, Type ... Values> struct anyOfValue
 {
  private:
  using resultType = std :: common_type_t<decltype(Operator <Values> :: value)...>;
  using reductor = logicalOperatorsForType<resultType>;
  public:
  constexpr const static auto value = reductor :: template LogicalOr <static_cast<resultType>(Operator <Values> :: value)...> :: value;
 };
}
#endif

