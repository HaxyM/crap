#ifndef CRAP_ALGORITHM_TRANSFORMVALUE
#define CRAP_ALGORITHM_TRANSFORMVALUE

#include "../utility.d/commontype.h"
#include "../utility.d/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type> class, Type...> struct transformValue;

 template <class Type, template <Type> class Operator> struct transformValue<Type, Operator>
 {
  using resultType = Type;
  template <template <resultType...> class Container = valueListForType <resultType> :: template type>
  using type = Container<>;
 };

 template <class Type, template <Type> class Operator, Type ... Values> struct transformValue
 {
  using resultType = typename commonType <decltype(Operator <Values> :: value)...> :: type;
  template <template <resultType...> class Container = valueListForType <resultType> :: template type>
  using type = Container<(static_cast<resultType>(Operator <Values> :: value))...>;
 };
}
#endif

