#ifndef CRAP_FUNCTIONAL_DIVIDESVALUE
#define CRAP_FUNCTIONAL_DIVIDESVALUE

#include "../utility/language.h"

#if CPP17
#else
#include "../numeric/accumulatevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct dividesValue;

 #if CPP17
 #else
 template <class Type, Type Value1, Type Value2> struct dividesValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 / Value2);
 };
 #endif

 template <class Type, Type FirstValue, Type ... Rest> struct dividesValue<Type, FirstValue, Rest...>
 {
  #if CPP17
  constexpr const static auto value = (FirstValue / ... / Rest);
  #else
  private:
  template <Type Value1, Type Value2> using Operator = dividesValue<Type, Value1, Value2>;
  public:
  constexpr const static auto value = accumulateValue <Type, FirstValue, Operator, Rest...> :: value;
  #endif
 };
}
#endif

