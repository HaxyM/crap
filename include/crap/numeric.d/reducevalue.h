#ifndef CRAP_NUMERIC_REDUCEVALUE
#define CRAP_NUMERIC_REDUCEVALUE

#include "../utility.d/bisectvalue.h"

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

 template <class Type, template <Type...> class Operator, Type Value1, Type Value2>
	 struct reduceValue<Type, Operator, Value1, Value2>
 {
  constexpr const static auto value = Operator <Value1, Value2> :: value;
 };

 template <class Type, template <Type...> class Operator, Type ... Values> struct reduceValue
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using This = reduceValue<Type, Operator, SubValues...>;
  constexpr const static Type lower = values :: template lower <This> :: value;
  constexpr const static Type upper = values :: template upper <This> :: value;
  public:
  constexpr const static auto value = Operator <lower, upper> :: value;
 };
}
#endif

