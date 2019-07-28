#ifndef CRAP_NUMERIC_REDUCEVALUE
#define CRAP_NUMERIC_REDUCEVALUE

#include "../utility/valuelist.h"

namespace crap
{
 template <class Type, template <Type...> class, Type...> struct reduceValue;

 template <class Type, template <Type...> class Operator> struct reduceValue<Type, Operator>
 {
  constexpr const static auto value = Operator <> :: value;
 };

 template <class Type, template <Type...> class Operator, Type Value> struct reduceValue<Type, Operator, Value>
 {
  constexpr const static auto value = Operator <Value> :: value;
 };

 template <class Type, template <Type...> class Operator, Type Value1, Type Value2> struct reduceValue<Type, Operator, Value1, Value2>
 {
  constexpr const static auto value = Operator <Value1, Value2> :: value;
 };

 template <class Type, template <Type...> class Operator, Type ... Values> struct reduceValue
 {
  private:
  using values = valueList<Type, Values...>;
  constexpr const static std :: size_t half = values :: size / 2u;
  template <Type ... SubValues> using This = reduceValue<Type, Operator, SubValues...>;
  using lower = typename values :: template till<half, This>;
  using upper = typename values :: template since<half, This>;
  public:
  constexpr const static auto value = Operator <lower :: value, upper :: value> :: value;
 };
}
#endif

