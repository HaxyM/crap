#ifndef CRAP_RATIO_MODFTYPE
#define CRAP_RATIO_MODFTYPE

#include <type_traits>

#include "contracttype.h"
#include "minustype.h"
#include "trunctype.h"
#include "valueratio.h"
#include "../cmath.d/modftype.h"

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct modfType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using value = typename contractType <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  public:
  using intPart = typename truncType <value> :: type;
  using type = typename minusType <value, intPart> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename modfType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 modf(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: modfType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: modf(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif
