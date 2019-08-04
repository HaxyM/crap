#ifndef CRAP_ALGORITHM_TRANSFORMVALUE
#define CRAP_ALGORITHM_TRANSFORMVALUE

#include "../utility/valuelistfortype.h"

#include <type_traits>

namespace crap
{
 template <class Type, template <Type> class Operator, Type ... Values> struct transformValue
 {
  using resultType = std :: common_type_t<decltype(Operator <Values> :: value)...>;
  template <template <resultType...> class Container = valueListForType <resultType> :: template type>
  using type = Container<(static_cast<resultType>(Operator <Values> :: value))...>;
 };
}
#endif

