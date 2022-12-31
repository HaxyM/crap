#include <cstddef>
#include <type_traits>

#include "costype.h"
#include "dividestype.h"
#include "sintype.h"
#include "valueratio.h"
#include "../cmath.d/tantype.h"

#ifndef CRAP_RATIO_TANTYPE
#define CRAP_RATIO_TANTYPE

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct tanType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using x = valueRatio<Type, Sign, Numerator, Denominator>;
  using numerator = typename sinType <x> :: type;
  using denominator = typename cosType <x> :: type;
  public:
  using type = typename dividesType <numerator, denominator> :: type;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename tanType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 tan(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: tanType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: tan(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif

