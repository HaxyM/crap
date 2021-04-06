#ifndef CRAP_ALGORITHM_TRANSFORM2VALUE
#define CRAP_ALGORITHM_TRANSFORM2VALUE

#include "../utility/commontype.h"
#include "../utility/valuelistfortype.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct transform2Value;

 template <class Type, template <Type, Type> class Operator> struct transform2Value<Type, Operator>
 {
  template <Type ... Values2> struct with;
  template <Type ... Values2> using resultType = typename with <Values2...> :: resultType;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1> struct transform2Value
 {
  template <Type ... Values2> struct with;
  template <Type ... Values2> using resultType = typename with <Values2...> :: resultType;
 };

 template <class Type, template <Type, Type> class Operator> template <Type ... Values2> struct transform2Value <Type, Operator> :: with
 {
  static_assert(sizeof...(Values2) == 0u, "Vectors does not have same size.");
  using resultType = Type;
  template <template <resultType...> class Container = valueListForType <resultType> :: template type>
  using type = Container<>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values1>
 template <Type ... Values2> struct transform2Value <Type, Operator, Values1...> :: with
 {
  static_assert(sizeof...(Values1) == sizeof...(Values2), "Vectors does not have same size.");
  using resultType = typename commonType <decltype(Operator <Values1, Values2> :: value)...> :: type;
  template <template <resultType...> class Container = valueListForType <resultType> :: template type>
  using type = Container<(static_cast<resultType>(Operator <Values1, Values2> :: value))...>;
 };
}
#endif

