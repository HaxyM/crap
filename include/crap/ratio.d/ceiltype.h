#ifndef CRAP_RATIO_CEILTYPE
#define CRAP_RATIO_CEILTYPE

#include <type_traits>

#include "contracttype.h"
#include "valueratio.h"
#include "../cmath.d/ceiltype.h"
#include "../numbers.d/identity.h"

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct ceilType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using value = typename contractType <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  constexpr const static bool whole = ((value :: num % value :: den) == 0u);
  constexpr const static bool negative = (Sign == '-');
  constexpr const static typename value :: valueType newNum = value :: num / value :: den;
  public:
  using type = valueRatio<Type, Sign, ((whole || negative) ? newNum : (newNum + 1u)), identity <typename value :: valueType> :: value>;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename ceilType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 ceil(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: ceilType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: ceil(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif
