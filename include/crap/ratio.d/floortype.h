#ifndef CRAP_RATIO_FLOORTYPE
#define CRAP_RATIO_FLOORTYPE

#include <type_traits>

#include "contracttype.h"
#include "valueratio.h"
#include "../cmath.d/floortype.h"
#include "../numbers.d/identity.h"

namespace crap
{
 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct floorType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using value = typename contractType <valueRatio<Type, Sign, Numerator, Denominator> > :: type;
  constexpr const static bool whole = ((value :: num % value :: den) == 0u);
  constexpr const static bool positive = (Sign == '+');
  constexpr const static typename value :: numeratorType newNum = value :: num / value :: den;
  public:
  using type = valueRatio<Type, Sign, ((whole || positive) ? newNum : (newNum + 1u)), identity <typename value :: denominatorType> :: value>;
 };

 template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 constexpr typename floorType <valueRatio<Type, Sign, Numerator, Denominator> > :: type
	 floor(valueRatio<Type, Sign, Numerator, Denominator>) noexcept;
}

template <class Type, char Sign, typename std :: make_unsigned <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
inline constexpr typename crap :: floorType <crap :: valueRatio<Type, Sign, Numerator, Denominator> > :: type
crap :: floor(crap :: valueRatio<Type, Sign, Numerator, Denominator>) noexcept
{
 return {};
}
#endif
