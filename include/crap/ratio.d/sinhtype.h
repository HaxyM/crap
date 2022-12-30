#include <cstddef>
#include <type_traits>

#include "dividestype.h"
#include "exptype.h"
#include "identity.h"
#include "minustype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../cmath.d/sinhtype.h"

#ifndef CRAP_RATIO_SINHTYPE
#define CRAP_RATIO_SINHTYPE

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct sinhType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using eToX = typename expType <passed> :: type;
  using eToMX = valueRatio<Type, eToX :: sign, eToX :: den, eToX :: num>;
  using numerator = typename minusType <eToX, eToMX> :: type;
  public:
  using type = typename dividesType <numerator, const2> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename sinhType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 sinh(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: sinhType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: sinh(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

