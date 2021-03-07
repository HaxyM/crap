#ifndef CRAP_FUNCTIONAL_MODULUSVALUE
#define CRAP_FUNCTIONAL_MODULUSVALUE

#include "../utility/language.h"

#if CPP17
#else
#include "../numeric/accumulatevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct modulusValue;

 #if CPP17
 #else
 template <class Type, Type Value> struct modulusValue<Type, Value>
 {
  constexpr const static auto value = Value;
 };

 template <class Type, Type Value1, Type Value2> struct modulusValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 % Value2);
 };
 #endif

 template <class Type, Type FirstValue, Type ... Rest> struct modulusValue<Type, FirstValue, Rest...>
 {
  #if CPP17
  constexpr const static auto value = (FirstValue % ... % Rest);
  #else
  private:
  template <Type ... SubValue> using This = modulusValue<Type, SubValues...>
  public:
  constexpr const static auto value = accumulateValue <Type, This, FirstValue, Rest...> :: value;
  #endif
 };
}
#endif

