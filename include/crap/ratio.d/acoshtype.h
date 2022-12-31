#include <cstddef>
#include <type_traits>

#include "identity.h"
#include "logtype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "sqrttype.h"
#include "valueratio.h"
#include "../cmath.d/acoshtype.h"

#ifndef CRAP_RATIO_ACOSHTYPE
#define CRAP_RATIO_ACOSHTYPE

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct acoshType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using sqrX = typename multipliesType <x, x> :: type;
  using const1 = typename identity <x> :: type;
  using elem1 = typename minusType <sqrX, const1> :: type;
  using elem2 = typename sqrtType <elem1> :: type;
  using elem3 = typename plusType <x, elem2> :: type;
  public:
  using type = typename logType <elem3> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename acoshType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 acosh(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: acoshType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: acosh(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

