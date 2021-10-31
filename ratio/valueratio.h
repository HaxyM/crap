#ifndef CRAP_RATIO_VALUERATIO
#define CRAP_RATIO_VALUERATIO

#include <type_traits>

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator> struct valueRatio
 {
  static_assert((Sign == '+') || (Sign == '-'), "Sign must be either '+' or '-'");
  using type = valueRatio<Type, Sign, Numerator, Denominator>;
  using numeratorType = typename std :: make_unsigned <Type> :: type;
  using denominatorType = typename std :: make_unsigned <Type> :: type;
  constexpr const static char sign = Sign;
  constexpr static typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type num = Numerator;
  constexpr static typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type den = Denominator;
 };
}
#endif
