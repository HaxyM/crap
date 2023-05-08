#ifndef CRAP_RATIO_IDENTITY
#define CRAP_RATIO_IDENTITY

#include <type_traits>

#include "valueratio.h"
#include "../numbers.d/identity.h"
#include "../utility.d/typeidentity.h"

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct identity<valueRatio<Type, Sign, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, '+', identity <Type> :: value, identity <Type> :: value> >
 {};
}
#endif

