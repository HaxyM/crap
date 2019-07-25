#ifndef CRAP_NUMERIC_PARTIALSUMVALUE
#define CRAP_NUMERIC_PARTIALSUMVALUE

#include "../utility/valuelist.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct partialSumValue;

 template <class Type, template <Type, Type> class Operator> struct partialSumValue<Type, Operator>
 {
  using type = valueList<Type>;
 };

 template <class Type, template <Type, Type> class Operator, Type Value> struct partialSumValue<Type, Operator, Value>
 {
  using type = valueList<Type, Value>;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct partialSumValue
 {
  private:
  using values = valueList<Type, Values...>;
  template <Type ... SubValues> using This = partialSumValue<Type, Operator, SubValues...>;
  constexpr const static std :: size_t half = (values :: size) / 2u;
  using lower = typename values :: template till <half, This> :: type;
  using upper = typename values :: template since <half, This> :: type;
  constexpr const static Type lowerLast = lower :: template at<lower :: size - 1u>;
  template <Type ... LowerValues, Type ... UpperValues> static valueList<Type, LowerValues..., (lowerLast + UpperValues)...> merge(valueList<Type, LowerValues...>, valueList<Type, UpperValues...>);
  public:
  using type = decltype(merge(lower{}, upper{}));
 };
}
#endif

