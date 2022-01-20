#ifndef CRAP_RATIO_CBRTTYPE
#define CRAP_RATIO_CBRTTYPE

#include "dividestype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../cmath.d/cbrttype.h"
#include "../functional.d/dividestype.h"
#include "../functional.d/minustype.h"
#include "../functional.d/multipliestype.h"
#include "../functional.d/plustype.h"

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct cbrtType<valueRatio<Type, Sign, Numerator, Denominator>, 0u>
 {
  using type = valueRatio<Type, Sign, Numerator, Denominator>;
 };
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 struct cbrtType<valueRatio<Type, Sign, Numerator, Denominator>, Steps>
 {
  private:
  using z = valueRatio<Type, Sign, Numerator, Denominator>;
  using x = typename cbrtType <z, Steps - 1u> :: type;
  using x2 = typename multipliesType <x, x> :: type;
  using partNum = typename minusType <typename multipliesType <x, x, x> :: type, z> :: type;
  using part = typename dividesType <partNum, typename plusType <x2, x2, x2> :: type> :: type;
  public:
  using type = typename minusType <x, part> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename cbrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 cbrt(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: cbrtType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: cbrt(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif
