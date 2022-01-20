#ifndef CRAP_NUMERIC_LCMVALUE
#define CRAP_NUMERIC_LCMVALUE

#include "../utility.d/language.h"
#include "reducevalue.h"

#if CPP17
#include <numeric>
#else
#include "gcdvalue.h"
#include <type_traits>
#endif

namespace crap
{
 template <class Type, Type...> struct lcmValue;

 template <class Type> struct lcmValue<Type>
 {
  constexpr const static Type value = static_cast<Type>(1);
 };

 template <class Type, Type Value> struct lcmValue<Type, Value>
 {
  constexpr const static Type value = Value;
 };

 template <class Type, Type Value1, Type Value2> struct lcmValue<Type, Value1, Value2>
 {
  #if CPP17
  constexpr const static Type value = std :: lcm(Value1, Value2);
  #else
  private:
  constexpr const static auto Gcd = gcdValue <Type, Value1, Value2> :: value;
  public:
  constexpr const static Type value = (Value1 / Gcd) * Value2;
  #endif
 };

 template <class Type, Type ... Values> struct lcmValue
 {
  private:
  template <Type ... SubValues> using This = lcmValue<Type, SubValues...>;
  public:
  constexpr const static Type value = reduceValue <Type, This, Values...> :: value;
 };
}
#endif

