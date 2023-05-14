#ifndef CRAP_RATIO_ABSTYPE
#define CRAP_RATIO_ABSTYPE

#include "valueratio.h"
#include "../numeric.d/abstype.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct absType<valueRatio<Type, Sign, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, '+', Numerator, Denominator> > {};
}
#endif
