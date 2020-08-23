#ifndef CRAP_RATIO_CONTRACTTYPE
#define CRAP_RATIO_CONTRACTTYPE

#include <type_traits>

#include "valueratio.h"
#include "../numeric/absvalue.h"
#include "../numeric/contracttype.h"
#include "../numeric/gcdvalue.h"
#include "../numeric/zero.h"

namespace crap
{
 template <typename Type, typename std :: make_signed <Type> :: type Numerator, typename std :: make_unsigned <Type> :: type Denominator>
	 struct contractType<valueRatio<Type, Numerator, Denominator> >
 {
  private:
  using numeratorType = typename std :: add_const <typename std :: make_signed <Type> :: type> :: type;
  using denominatorType = typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type;
  constexpr static denominatorType absolute = static_cast<denominatorType>(absValue <Type, Numerator> :: value);
  constexpr static numeratorType contractedNumerator = static_cast<numeratorType>(absolute / gcdValue <denominatorType, absolute, Denominator> :: value);
  constexpr static numeratorType newNumerator = ((Numerator < zero <numeratorType> :: value) ? (-contractedNumerator) : contractedNumerator);
  constexpr static denominatorType newDenominator = Denominator / gcdValue <denominatorType, absolute, Denominator> :: value;
  public:
  using type = valueRatio<Type, newNumerator, newDenominator>;
 };
}
#endif

