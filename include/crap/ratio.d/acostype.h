#include <cstddef>
#include <type_traits>

#include "atantype.h"
#include "dividestype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "sqrttype.h"
#include "valueratio.h"
#include "../cmath.d/acoshtype.h"

#ifndef CRAP_RATIO_ACOSTYPE
#define CRAP_RATIO_ACOSTYPE

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct acosType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using sqrX = typename multipliesType <x, x> :: type;
  using const1 = typename identity <x> :: type;
  using elem1 = typename minusType <const1, sqrX> :: type;
  using elem2 = typename sqrtType <elem1> :: type;
  using elem3 = typename plusType <const1, x> :: type;
  using elem4 = typename dividesType <elem2, elem3> :: type;
  using elem5 = typename atanType <elem4> :: type;
  public:
  using type = typename plusType <elem5, elem5> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename acosType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 acos(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: acosType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: acos(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

