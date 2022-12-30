#include <cstddef>
#include <type_traits>

#include "dividestype.h"
#include "exptype.h"
#include "identity.h"
#include "plustype.h"
#include "valueratio.h"
#include "../cmath.d/coshtype.h"

#ifndef CRAP_RATIO_COSHTYPE
#define CRAP_RATIO_COSHTYPE

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct coshType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using const2 = typename plusType <const1, const1> :: type;
  using eToX = typename expType <passed> :: type;
  using eToMX = valueRatio<Type, eToX :: sign, eToX :: den, eToX :: num>;
  using numerator = typename plusType <eToX, eToMX> :: type;
  public:
  using type = typename dividesType <numerator, const2> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename coshType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 cosh(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: coshType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: cosh(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

