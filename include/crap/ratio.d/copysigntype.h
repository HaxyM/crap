#ifndef CRAP_RATIO_COPYSIGNTYPE
#define CRAP_RATIO_COPYSIGNTYPE

#include <type_traits>

#include "contracttype.h"
#include "valueratio.h"
#include "../cmath.d/copysigntype.h"
#include "../utility.d/typeidentity.h"

namespace crap
{
 template <class magnitudeType, char magnitudeSign, magnitudeType magnitudeNumerator, magnitudeType magnitudeDenominator, class signType, char signSign, signType signNumerator, signType signDenominator>
	 struct copysignType<valueRatio<magnitudeType, magnitudeSign, magnitudeNumerator, magnitudeDenominator>, valueRatio<signType, signSign, signNumerator, signDenominator> >
	 : typeIdentity<typename contractType <valueRatio<magnitudeType, signSign, magnitudeNumerator, magnitudeDenominator> > :: type>
	 {};
}
#endif

