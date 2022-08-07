#ifndef CRAP_RATIO_ZERO
#define CRAP_RATIO_ZERO

#include <type_traits>

#include "valueratio.h"
#include "../numeric.d/zero.h"
#include "../numbers.d/identity.h"
#include "../utility.d/typeidentity.h"

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type>
	 struct zero<valueRatio<Type, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, '+', zero <typename std :: make_unsigned <Type> :: type> :: value, identity <typename std :: make_unsigned <Type> :: type> :: value> >
 {};
}
#endif

