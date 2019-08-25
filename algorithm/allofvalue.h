#ifndef CRAP_ALGORITHM_ALLOFVALUE
#define CRAP_ALGORITHM_ALLOFVALUE

#include "../functional/logicalandvalue.h"

#include <type_traits>

namespace crap
{
 template <class Type, template <Type> class Operator, Type ... Values> struct allOfValue
 {
  private:
  using resultType = std :: common_type_t<decltype(Operator <Values> :: value)...>;
  public:
  constexpr const static auto value = logicalAndValue <resultType, static_cast<resultType>(Operator <Values> :: value)...> :: value;
 };
}
#endif

