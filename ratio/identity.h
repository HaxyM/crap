#ifndef CRAP_RATIO_IDENTITY
#define CRAP_RATIO_IDENTITY

#include <type_traits>

#include "valueratio.h"
#include "../numeric/identity.h"
#include "../utility/typeidentity.h"

namespace crap
{
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type>
	 struct zero<valueRatio<Type, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, identity <typename std :: make_signed <Type> :: type> :: value, identity <typename std :: make_unsigned <Type> :: type> :: value> >
 {};
}
#endif

