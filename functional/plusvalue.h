#ifndef CRAP_FUNCTIONAL_PLUSVALUE
#define CRAP_FUNCTIONAL_PLUSVALUE

#include "../utility/language.h"

#if CPP17
#else
#include "../numeric/reducevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct plusValue;

 template <class Type> struct plusValue<Type>
 {
  constexpr const static auto value = static_cast<Type>(0);
 };

 template <class Type, Type Value> struct plusValue<Type, Value>
 {
  constexpr const static auto value = Value;
 };
 
 template <class Type, Type Value1, Type Value2> struct plusValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 + Value2);
 };

 template <class Type, Type ... Values> struct plusValue
 {
  #if CPP17
  constexpr const static auto value = (Values + ...);
  #else
  private:
  template <Type ... SubValues> using This = plusValue<Type, SubValues...>;
  public:
  constexpr const static auto value = reduceValue <Type, This, Values...> :: value;
  #endif
 };
}
#endif

