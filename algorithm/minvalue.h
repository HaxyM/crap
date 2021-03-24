#ifndef CRAP_ALGORITHM_MINVALUE
#define CRAP_ALGORITHM_MINVALUE

#include "../numeric/reducevalue.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct minValue;

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct minValue<Type, Operator, Value>
 {
  constexpr const static Type value = Value;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct minValue<Type, Operator, Value1, Value2>
 {
  constexpr const static Type value = ((Operator <Value1, Value2> :: value) ? Value1 : Value2);
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values>
	 struct minValue
 {
  private:
  template <Type ... SubValues> using This = minValue<Type, Operator, SubValues...>;
  public:
  constexpr const static Type value = reduceValue <Type, This, Values...> :: value;
 };
}
#endif
