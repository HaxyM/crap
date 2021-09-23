#ifndef CRAP_RATIO_ABSTYPE
#define CRAP_RATIO_ABSTYPE

#include "valueratio.h"
#include "../numeric/abstype.h"
#include "../utility/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct absType<valueRatio<Type, Sign, Numerator, Denominator> >
	 : typeIdentity<valueRatio<Type, '+', Numerator, Denominator> > {};
}
#endif
