#include <cstddef>
#include <type_traits>

#include "dividestype.h"
#include "identity.h"
#include "logtype.h"
#include "minustype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../cmath.d/atanhtype.h"

#ifndef CRAP_RATIO_ATANHTYPE
#define CRAP_RATIO_ATANHTYPE

namespace crap
{
 template <class Type, char Sign, Type Numerator, Type Denominator>
	 struct atanhType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <x> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using elem1 = typename plusType <const1, x> :: type;
  using elem2 = typename minusType <const1, x> :: type;
  using elem3 = typename dividesType <elem1, elem2> :: type;
  using elem4 = typename logType <elem3> :: type;
  public:
  using type = typename dividesType <elem4, const2> :: type;
 };

 template <class Type, char Sign, Type Numerator, Type Denominator>
	 constexpr typename atanhType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 atanh(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, Type Numerator, Type Denominator>
inline constexpr typename crap :: atanhType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: atanh(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

