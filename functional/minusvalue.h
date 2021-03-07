#ifndef CRAP_FUNCTIONAL_MINUSVALUE
#define CRAP_FUNCTIONAL_MINUSVALUE

#include "../utility/language.h"

#if CPP17
#else
#include "../numeric/accumulatevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct minusValue;

 #if CPP17
 #else
 template <class Type, Type Value> struct minusValue<Type, Value>
 {
  constexpr const static auto value = Value;
 };

 template <class Type, Type Value1, Type Value2> struct minusValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 - Value2);
 };
 #endif

 template <class Type, Type FirstValue, Type ... Rest> struct minusValue<Type, FirstValue, Rest...>
 {
  #if CPP17
  constexpr const static auto value = (FirstValue - ... - Rest);
  #else
  private:
  template <Type ... SubValues> using This = minusValue<Type, SubValues...>;
  public:
  constexpr const static auto value = accumulateValue <Type, This, FirstValue, Rest...> :: value;
  #endif
 };
}
#endif

