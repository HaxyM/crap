#ifndef CRAP_RATIO_CONTRACTTYPE
#define CRAP_RATIO_CONTRACTTYPE

#include <type_traits>

#include "valueratio.h"
#include "../numeric.d/contracttype.h"
#include "../numeric.d/gcdvalue.h"

namespace crap
{
 template <typename Type, char Sign, Type Numerator, Type Denominator>
	 struct contractType<valueRatio<Type, Sign, Numerator, Denominator> >
 {
  private:
  using valueType = typename std :: add_const <Type> :: type;
  constexpr static valueType gcd = gcdValue <Type, Numerator, Denominator> :: value;
  public:
  using type = valueRatio<Type, Sign, Numerator / gcd, Denominator / gcd>;
 };
}
#endif

