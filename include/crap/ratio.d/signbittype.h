#ifndef CRAP_RATIO_SIGNBITTYPE
#define CRAP_RATIO_SIGNBITTYPE

#include <type_traits>

#include "valueratio.h"
#include "../cmath.d/signbittype.h"

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct signbitType<valueRatio<Type, Sign, Numerator, Denominator> >
	 : std :: integral_constant<bool, Sign == '-'> {};

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr bool signbit(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr bool crap :: signbit(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return crap :: signbitType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: value;
}
#endif
