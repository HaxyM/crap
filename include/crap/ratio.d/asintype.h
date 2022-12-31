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

#ifndef CRAP_RATIO_ASINTYPE
#define CRAP_RATIO_ASINTYPE

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct asinType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using sqrX = typename multipliesType <x, x> :: type;
  using const1 = typename identity <x> :: type;
  using elem1 = typename minusType <const1, sqrX> :: type;
  using elem2 = typename sqrtType <elem1> :: type;
  using elem3 = typename dividesType <x, elem2> :: type;
  public:
  using type = typename atanType <elem3> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename asinType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 asin(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: asinType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: asin(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

