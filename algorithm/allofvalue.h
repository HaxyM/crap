#ifndef CRAP_ALGORITHM_ALLOFVALUE
#define CRAP_ALGORITHM_ALLOFVALUE

#include "../functional/logicalandvalue.h"
#include "../utility/commontype.h"

#include <type_traits>

namespace crap
{
 template <class Type, template <Type> class Operator, Type ... Values> struct allOfValue
 {
  private:
  using resultType = typename commonType <decltype(Operator <Values> :: value)...> :: type;
  public:
  constexpr const static auto value = logicalAndValue <resultType, static_cast<resultType>(Operator <Values> :: value)...> :: value;
 };
}
#endif

