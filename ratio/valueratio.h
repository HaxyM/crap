#ifndef CRAP_RATIO_VALUERATIO
#define CRAP_RATIO_VALUERATIO

#include <type_traits>

namespace crap
{
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator> struct valueRatio
 {
  using type = valueRatio<Type, Numerator, Denominator>;
  using numeratorType = typename std :: make_signed <Type> :: type;
  using denominatorType = typename std :: make_unsigned <Type> :: type;
  constexpr static typename std :: add_const <typename std :: make_signed <Type> :: type> :: type num = Numerator;
  constexpr static typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type den = Denominator;
 };
}
#endif

