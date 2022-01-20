#ifndef CRAP_ALGORITHM_MINMAXELEMENTVALUE
#define CRAP_ALGORITHM_MINMAXELEMENTVALUE

#include <cstddef>

#include "../utility.d/bisectvalue.h"

namespace crap
{
 template <class Type, template <Type, Type> class, Type...> struct minMaxElementValue;

 template <class Type, template <Type, Type> class Operator> struct minMaxElementValue<Type, Operator>
 {
  constexpr const static std :: size_t maximum = 0u;
  constexpr const static std :: size_t minimum = 0u;
  constexpr const static std :: size_t npos = 0u;
 };

 template <class Type, template <Type, Type> class Operator, Type Value>
	 struct minMaxElementValue<Type, Operator, Value>
 {
  template <class NewType, template <NewType, NewType> class, NewType...> friend struct minMaxElementValue;
  private:
  constexpr const static Type maxValue = Value;
  constexpr const static Type minValue = Value;
  public:
  constexpr const static std :: size_t maximum = 0u;
  constexpr const static std :: size_t minimum = 0u;
  constexpr const static std :: size_t npos = 1u;
 };

 template <class Type, template <Type, Type> class Operator, Type Value1, Type Value2>
	 struct minMaxElementValue<Type, Operator, Value1, Value2>
 {
  template <class NewType, template <NewType, NewType> class, NewType...> friend struct minMaxElementValue;
  private:
  constexpr const static Type maxValue = ((Operator <Value1, Value2> :: value) ? Value2 : Value1);
  constexpr const static Type minValue = ((Operator <Value2, Value1> :: value) ? Value2 : Value1);
  public:
  constexpr const static std :: size_t maximum = ((Operator <Value1, Value2> :: value) ? 1u : 0u);
  constexpr const static std :: size_t minimum = ((Operator <Value2, Value1> :: value) ? 1u : 0u);
  constexpr const static std :: size_t npos = 2u;
 };

 template <class Type, template <Type, Type> class Operator, Type ... Values> struct minMaxElementValue
 {
  template <class NewType, template <NewType, NewType> class, NewType...> friend struct minMaxElementValue;
  private:
  template <Type ... SubValues> using This = minMaxElementValue<Type, Operator, SubValues...>;
  using lower = typename bisectValue <Type, Values...> :: template lower<This>;
  using upper = typename bisectValue <Type, Values...> :: template upper<This>;
  constexpr const static Type maxValue =
	  ((Operator <lower :: maxValue, upper :: maxValue> :: value) ? (upper :: maxValue) : (lower :: maxValue));
  constexpr const static Type minValue =
	  ((Operator <upper :: minValue, lower :: minValue> :: value) ? (upper :: minValue) : (lower :: minValue));
  public:
  constexpr const static std :: size_t maximum =
	  ((Operator <lower :: maxValue, upper :: maxValue> :: value) ? (lower :: npos + upper :: maximum) : (lower :: maximum));
  constexpr const static std :: size_t minimum =
	  ((Operator <upper :: minValue, lower :: minValue> :: value) ? (lower :: npos + upper :: minimum) : (lower :: minimum));
  constexpr const static std :: size_t npos = sizeof...(Values);
 };
}
#endif

