#ifndef CRAP_RATIO_IDENTITY
#define CRAP_RATIO_IDENTITY

#include <type_traits>

#include "valueratio.h"
#include "../numbers.d/identity.h"
#include "../utility.d/typeidentity.h"

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct identity<valueRatio<Type, Sign, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, '+', identity <typename std :: make_unsigned <Type> :: type> :: value, identity <typename std :: make_unsigned <Type> :: type> :: value> >
 {};
}
#endif

