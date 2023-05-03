#ifndef CRAP_RATIO_EQUALTOTYPE
#define CRAP_RATIO_EQUALTOTYPE

#include <type_traits>

#include "valueratio.h"
#include "../functional.d/equaltotype.h"
#include "../numeric.d/gcdvalue.h"

namespace crap
{
 template <class Type, char Sign1, char Sign2, Type Numerator1, Type Denominator1, Type Numerator2, Type Denominator2>
 struct equalToType<valueRatio<Type, Sign1, Numerator1, Denominator1>, valueRatio<Type, Sign2, Numerator2, Denominator2> >
 {
  private:
  using valueType = typename std :: add_const <Type> :: type;
  constexpr static valueType gcd1 = gcdValue <Type, Numerator1, Denominator1> :: value;
  constexpr static valueType gcd2 = gcdValue <Type, Numerator2, Denominator2> :: value;
  constexpr static const bool numEqual = ((Numerator1 / gcd1) == (Numerator2 / gcd2));
  constexpr static const bool denEqual = ((Denominator1 / gcd1) == (Denominator2 / gcd2));
  public:
  constexpr static const bool value = (Sign1 == Sign2) && numEqual && denEqual;
 };

 template <class Type1, char Sign1, Type1 Numerator1, Type1 Denominator1, class Type2, char Sign2, Type2 Numerator2, Type2 Denominator2>
 struct equalToType<valueRatio<Type1, Sign1, Numerator1, Denominator1>, valueRatio<Type2, Sign2, Numerator2, Denominator2> >
	 : equalToType<
		valueRatio<typename std :: common_type <Type1, Type2> :: type, Sign1,
		static_cast<typename std :: common_type <Type1, Type2> :: type>(Numerator1),
		static_cast<typename std :: common_type <Type1, Type2> :: type>(Denominator1)>,
		valueRatio<typename std :: common_type <Type1, Type2> :: type, Sign2,
		static_cast<typename std :: common_type <Type1, Type2> :: type>(Numerator2),
		static_cast<typename std :: common_type <Type1, Type2> :: type>(Denominator2)> >
	{};
}

template <class Type1, class Type2, char Sign1, char Sign2, Type1 Numerator1, Type1 Denominator1, Type2 Numerator2, Type2 Denominator2>
inline constexpr bool operator == (crap :: valueRatio<Type1, Sign1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Sign2, Numerator2, Denominator2> ) noexcept
{
 return crap :: equalToType <crap :: valueRatio<Type1, Sign1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Sign2, Numerator2, Denominator2> > :: value;
}
#endif
