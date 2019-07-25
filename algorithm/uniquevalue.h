#ifndef CRAP_ALGORITHM_UNIQUE
#define CRAP_ALGORITHM_UNIQUE

#include "../utility/valuelist.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct uniqueValue;
 
 template <class Type, template <Type, Type> class Operator> struct uniqueValue<Type, Operator>
 {
  using type = valueList<Type>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value> struct uniqueValue<Type, Operator, Value>
 {
  using type = valueList<Type, Value>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct uniqueValue
 {
  private:
  using values = valueList<Type, Values...>;
  template <Type ... SubValues> using This = uniqueValue<Type, Operator, SubValues...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  using lower = typename values :: template till <half, This> :: type;
  using upper = typename values :: template since <half, This> :: type;
  constexpr const static Type lowerLast = lower :: template at<lower :: size - 1u>;
  constexpr const static Type upperFirst = upper :: template at<0u>;
  constexpr const static bool shouldSkipUpperFirst = Operator <lowerLast, upperFirst> :: value;
  using upperToMerge = typename upper :: template since<shouldSkipUpperFirst ? 1u : 0u>; //Upper with or without first value
  template <Type ... LowerValues, Type ... UpperValues> static valueList<Type, LowerValues..., UpperValues...> merge(valueList<Type, LowerValues...>, valueList<Type, UpperValues...>);
  public:
  using type = decltype(merge(lower{}, upperToMerge{}));
 };
}
#endif

