#ifndef CRAP_RATIO_ZERO
#define CRAP_RATIO_ZERO

#include <type_traits>

#include "valueratio.h"
#include "../numeric/zero.h"
#include "../numeric/identity.h"
#include "../utility/typeidentity.h"

namespace crap
{
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type>
	 struct zero<valueRatio<Type, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, zero <typename std :: make_signed <Type> :: type> :: value, identity <typename std :: make_unsigned <Type> :: type> :: value> >
 {};
}
#endif

