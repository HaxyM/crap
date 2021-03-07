#ifndef CRAP_NUMERIC_ACCUMULATEVALUE
#define CRAP_NUMERIC_ACCUMULATEVALUE

#include <type_traits>

#include "../utility/bisectvalue.h"

namespace crap
{
 template <class Type, template <Type...> class, Type...> struct accumulateValue;

 template <class Type, template <Type...> class Operator> struct accumulateValue<Type, Operator>
	 : std :: integral_constant<decltype(Operator <> :: value), Operator <> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value> struct accumulateValue<Type, Operator, Value>
	 : std :: integral_constant<decltype(Operator <Value> :: value), Operator <Value> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value1, Type Value2> struct accumulateValue<Type, Operator, Value1, Value2>
	 : std :: integral_constant<decltype(Operator <Value1, Value2> :: value), Operator <Value1, Value2> :: value> {};

 template <class Type, template <Type...> class Operator, Type Value1, Type Value2, Type Value3> struct accumulateValue<Type, Operator, Value1, Value2, Value3>
 {
  private:
  constexpr const static Type subResult = Operator <Value1, Value2> :: value;
  public:
  constexpr const static Type value = Operator <subResult, Value3> :: value;
 };

 template <class Type, template <Type...> class Operator, Type ... Values> struct accumulateValue
 {
  private:
  using values = bisectValue<Type, Values...>;
  template <Type ... SubValues> using firstHalf = accumulateValue<Type, Operator, SubValues...>;
  constexpr const static Type firstHalfValue = values :: template lower <firstHalf> :: value;
  template <Type ... SubValues> using secondHalf = accumulateValue<Type, Operator, firstHalfValue, SubValues...>;
  public:
  constexpr const static Type value = values :: template upper <secondHalf> :: value;
 };
}
#endif

