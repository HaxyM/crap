#include <cstddef>
#include <type_traits>

#include "atantype.h"
#include "dividestype.h"
#include "identity.h"
#include "minustype.h"
#include "multipliestype.h"
#include "pi.h"
#include "plustype.h"
#include "sqrttype.h"
#include "valueratio.h"
#include "../cmath.d/acostype.h"

#ifndef CRAP_RATIO_ACOSTYPE
#define CRAP_RATIO_ACOSTYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct acosType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <x> :: type;
  using cond = typename plusType <const1, x> :: type;
  constexpr const static bool isZero = //FIXME: Add check if is zero.
	  equalToValue <decltype(cond :: num), cond :: num, zero <decltype(cond :: num)> :: value> :: value;
  template <bool, class> struct Implementation;
  template <class atanDenominator> struct Implementation<true, atanDenominator>;
  template <class atanDenominator> struct Implementation<false, atanDenominator>;
  public:
  using type = typename Implementation <isZero, cond> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class atanDenominator>
 struct acosType<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation<true, atanDenominator>
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  public:
  using type = typename pi <passed> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 template <class atanDenominator>
 struct acosType<valueRatio<Type, Sign, Numerator, Denominator> > :: template
	 Implementation<false, atanDenominator>
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using sqrX = typename multipliesType <x, x> :: type;
  using const1 = typename identity <x> :: type;
  using elem1 = typename minusType <const1, sqrX> :: type;
  using elem2 = typename sqrtType <elem1> :: type;
  using elem3 = typename dividesType <elem2, atanDenominator> :: type;
  using elem4 = typename atanType <elem3> :: type;
  public:
  using type = typename plusType <elem4, elem4> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename acosType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 acos(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: acosType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: acos(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

