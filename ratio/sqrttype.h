#ifndef CRAP_RATIO_SQRTTYPE
#define CRAP_RATIO_SQRTTYPE

#include "dividestype.h"
#include "minustype.h"
#include "multipliestype.h"
#include "plustype.h"
#include "valueratio.h"
#include "../cmath/sqrttype.h"
#include "../functional/dividestype.h"
#include "../functional/minustype.h"
#include "../functional/multipliestype.h"
#include "../functional/plustype.h"

#include <cstddef>
#include <type_traits>

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct sqrtType<valueRatio<Type, Sign, Numerator, Denominator>, 0u>
 {
  using type = valueRatio<Type, Sign, Numerator, Denominator>;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator, std :: size_t Steps>
	 struct sqrtType<valueRatio<Type, Sign, Numerator, Denominator>, Steps>
 {
  private:
  static_assert(Sign == '+', "Value must be positive.");
  using z = valueRatio<Type, Sign, Numerator, Denominator>;
  using x = typename sqrtType <z, Steps - 1u> :: type;
  using partNum = typename minusType <typename multipliesType <x, x> :: type, z> :: type;
  using part = typename dividesType <partNum, typename plusType <x, x> :: type> :: type;
  public:
  using type = typename minusType <x, part> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename sqrtType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 sqrt(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: sqrtType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: sqrt(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif
