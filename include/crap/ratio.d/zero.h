#ifndef CRAP_RATIO_ZERO
#define CRAP_RATIO_ZERO

#include <type_traits>

#include "valueratio.h"
#include "../numbers.d/identity.h"
#include "../numbers.d/zero.h"
#include "../utility.d/typeidentity.h"

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct zero<valueRatio<Type, Sign, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, '+', zero <Type> :: value, identity <Type> :: value> >
 {};
}
#endif

