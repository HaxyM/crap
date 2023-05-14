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
#include "../cmath.d/asintype.h"

#ifndef CRAP_RATIO_ASINTYPE
#define CRAP_RATIO_ASINTYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct asinType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using sqrX = typename multipliesType <x, x> :: type;
  using const1 = typename identity <x> :: type;
  using elem1 = typename minusType <const1, sqrX> :: type;
  using elem2 = typename sqrtType <elem1> :: type;
  using elem3 = typename plusType <const1, elem2> :: type;
  using elem4 = typename dividesType <x, elem3> :: type;
  using elem5 = typename atanType <elem4> :: type;
  public:
  using type = typename plusType <elem5, elem5> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename asinType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 asin(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: asinType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: asin(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

