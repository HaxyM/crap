#include <cstddef>
#include <type_traits>

#include "identity.h"
#include "logtype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "sqrttype.h"
#include "valueratio.h"
#include "../cmath.d/asinhtype.h"

#ifndef CRAP_RATIO_ASINHTYPE
#define CRAP_RATIO_ASINHTYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct asinhType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using sqrX = typename multipliesType <x, x> :: type;
  using const1 = typename identity <x> :: type;
  using elem1 = typename plusType <sqrX, const1> :: type;
  using elem2 = typename sqrtType <elem1> :: type;
  using elem3 = typename plusType <x, elem2> :: type;
  public:
  using type = typename logType <elem3> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename asinhType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 asinh(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: asinhType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: asinh(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

