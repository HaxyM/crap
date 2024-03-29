#ifndef CRAP_RATIO_NEGATETYPE
#define CRAP_RATIO_NEGATETYPE

#include "valueratio.h"
#include "../functional.d/negatetype.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct negateType<valueRatio<Type, Sign, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, ((Sign == '+') ? '-' : '+'), Numerator, Denominator> >
 {};
}
#endif
