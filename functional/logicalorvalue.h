#ifndef CRAP_FUNCTIONAL_LOGICALORVALUE
#define CRAP_FUNCTIONAL_LOGICALORVALUE

#include "../utility/language.h"

#if CPP17
#else
#include "../numeric/reducevalue.h"
#endif

namespace crap
{
 template <class Type, Type...> struct logicalOrValue;

 template <class Type> struct logicalOrValue<Type>
 {
  constexpr const static auto value = static_cast<Type>(false);
 };

 template <class Type, Type Value> struct logicalOrValue<Type, Value>
 {
  constexpr const static auto value = Value;
 };

 template <class Type, Type Value1, Type Value2> struct logicalOrValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 || Value2);
 };

 template <class Type, Type ... Values> struct logicalOrValue
 {
  #if CPP17
  constexpr const static auto value = (Values || ...);
  #else
  private:
  template <Type ... SubValues> using This = logicalOrValue<Type, SubValues...>;
  public:
  constexpr const static auto value = reduceValue <Type, This, Values...> :: value;
  #endif
 };
}
#endif

