#ifndef CRAP_RATIO_VALUERATIO
#define CRAP_RATIO_VALUERATIO

#include <type_traits>

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator> struct valueRatio
 {
  static_assert(std :: is_unsigned <Type> :: value, "Type must be unsigned.");
  static_assert((Sign == '+') || (Sign == '-'), "Sign must be either '+' or '-'.");
  using type = valueRatio<Type, Sign, Numerator, Denominator>;
  using valueType = Type;
  constexpr const static char sign = Sign;
  constexpr static typename std :: add_const <valueType> :: type num = Numerator;
  constexpr static typename std :: add_const <valueType> :: type den = Denominator;
 };
}
#endif
