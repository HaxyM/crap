#include <type_traits>

#include "exptype.h"
#include "identity.h"
#include "ln2.h"
#include "multipliestype.h"
#include "../cmath.d/exp2type.h"

#ifndef CRAP_RATIO_EXP2TYPE
#define CRAP_RATIO_EXP2TYPE

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct exp2Type<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using passed = valueRatio<Type, Sign, Numerator, Denominator>;
  using const1 = typename identity <passed> :: type;
  using exponent = typename multipliesType <passed, typename ln2 <const1> :: type> :: type;
  public:
  using type = typename expType <exponent> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename exp2Type <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 exp2(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: exp2Type <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: exp2(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

