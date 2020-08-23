#ifndef CRAP_RATIO_ABSTYPE
#define CRAP_RATIO_ABSTYPE


#include "valueratio.h"
#include "../numeric/absvalue.h"
#include "../utility/typeidentity.h"

namespace crap
{
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct absType<valueRatio<Type, Numerator, Denominator> >
	 : typeIdentity<valueRatio<absValue <typename std :: make_signed <Type> :: type, Numerator> :: value, Denominator> >
 {};
}
#endif

