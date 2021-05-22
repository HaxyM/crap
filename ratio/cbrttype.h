#ifndef CRAP_RATIO_CBRTTYPE
#define CRAP_RATIO_CBRTTYPE

#include "dividestype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../cmath/cbrttype.h"
#include "../functional/dividestype.h"
#include "../functional/minustype.h"
#include "../functional/multipliestype.h"
#include "../functional/plustype.h"

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct cbrtType<valueRatio<Type, Numerator, Denominator>, 0u>
 {
  using type = valueRatio<Type, Numerator, Denominator>;
 };
 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 struct cbrtType<valueRatio<Type, Numerator, Denominator>, Steps>
 {
  private:
  using z = valueRatio<Type, Numerator, Denominator>;
  using x = typename cbrtType <z, Steps - 1u> :: type;
  using x2 = typename multipliesType <x, x> :: type;
  using partNum = typename minusType <typename multipliesType <x, x, x> :: type, z> :: type;
  using part = typename dividesType <partNum, typename plusType <x2, x2, x2> :: type> :: type;
  public:
  using type = typename minusType <x, part> :: type;
 };

 template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename cbrtType <valueRatio<Type, Numerator, Denominator> > :: type
	 cbrt(valueRatio<Type, Numerator, Denominator>) noexcept;
}

template <class Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: cbrtType <crap :: valueRatio<Type, Numerator, Denominator> > :: type
crap :: cbrt(crap :: valueRatio<Type, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

