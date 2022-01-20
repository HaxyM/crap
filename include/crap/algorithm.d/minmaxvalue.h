#ifndef CRAP_ALGORITHM_MINMAXVALUE
#define CRAP_ALGORITHM_MINMAXVALUE

#include "../utility.d/bisectvalue.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct minMaxValue;

 template <class Type, template <Type, Type> class Operator, Type Value> struct minMaxValue<Type, Operator, Value>
 {
  constexpr const static Type minimum = Value;
  constexpr const static Type maximum = Value;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct minMaxValue<Type, Operator, Value1, Value2>
 {
  constexpr const static Type minimum = ((Operator <Value2, Value1> :: value) ? Value2 : Value1);
  constexpr const static Type maximum = ((Operator <Value2, Value1> :: value) ? Value1 : Value2);
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct minMaxValue
 {
  private:
  static_assert(sizeof...(Values) > 0u, "Extremum of empty set is not defined.");
  template <Type ... SubValues> using This = minMaxValue<Type, Operator, SubValues...>;
  using lower = typename bisectValue <Type, Values...> :: template lower<This>;
  using upper = typename bisectValue <Type, Values...> :: template upper<This>;
  public:
  constexpr const static Type minimum =
	  ((Operator <upper :: minimum, lower :: minimum> :: value) ? (upper :: minimum) : (lower :: minimum));
  constexpr const static Type maximum =
	  ((Operator <upper :: maximum, lower :: maximum> :: value) ? (lower :: maximum) : (upper :: maximum));
 };
}
#endif

