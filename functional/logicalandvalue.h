#ifndef CRAP_FUNCTIONAL_LOGICALANDVALUE
#define CRAP_FUNCTIONAL_LOGICALANDVALUE

namespace crap
{
 template <class Type, Type...> struct logicalAndValue;

 template <class Type> struct logicalAndValue<Type>
 {
  constexpr const static auto value = static_cast<Type>(true);
 };

 template <class Type, Type Value> struct logicalAndValue<Type, Value>
 {
  constexpr const static auto value = Value;
 };

 template <class Type, Type Value1, Type Value2> struct logicalAndValue<Type, Value1, Value2>
 {
  constexpr const static auto value = (Value1 && Value2);
 };

 template <class Type, Type ... Values> struct logicalAndValue
 {
  static_assert(sizeof...(Values) <= 2u, "Folding expressions are not supported.");
 };
}
#endif

