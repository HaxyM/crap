#ifndef CRAP_FUNCTIONAL_MULTIPLIESVALUE
#define CRAP_FUNCTIONAL_MULTIPLIESVALUE

#include "../utility/language.h"

#if CPP17
#else
#include "../numeric/reducevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct multipliesValue;

 template <class Type> struct multipliesValue<Type>
 {
  constexpr const static auto value = static_cast<Type>(1);
 };

 template <class Type, Type Value> struct multipliesValue<Type, Value>
 {
  constexpr const static auto value = Value;
 };

 template <class Type, Type Value1, Type Value2> struct multipliesValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 * Value2);
 };

 template <class Type, Type ... Values> struct multipliesValue
 {
  #if CPP17
  constexpr const static auto value = (Values * ...);
  #else
  private:
  template <Type ... SubValues> using This = multipliesValue<Type, SubValues...>;
  public:
  constexpr const static auto value = reduceValue <Type, This, Values...> :: value;
  #endif
 };
}
#endif

