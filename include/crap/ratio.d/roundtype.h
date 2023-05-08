#ifndef CRAP_RATIO_ROUNDTYPE
#define CRAP_RATIO_ROUNDTYPE

#include <type_traits>

#include "contracttype.h"
#include "valueratio.h"
#include "../cmath.d/roundtype.h"
#include "../numbers.d/identity.h"

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct roundType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using value = typename contractType <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  constexpr const static auto remainder = (value :: num % value :: den);
  constexpr const static bool roundDown = (Sign == '+') && ((value :: den - remainder) > remainder);
  constexpr const static bool roundUp = (Sign == '-') && ((value :: den - remainder) < remainder);
  constexpr const static typename value :: valueType newNum = value :: num / value :: den;
  public:
  using type = valueRatio<Type, Sign, ((Sign == '-') ? (roundUp ? (newNum + 1u) : newNum) : (roundDown ? newNum : (newNum + 1u))), identity <typename value :: valueType> :: value>;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename roundType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 round(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: roundType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: round(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif
