#ifndef CRAP_RATIO_NOTEQUALTOTYPE
#define CRAP_RATIO_NOTEQUALTOTYPE

#include <type_traits>

#include "valueratio.h"
#include "../functional/notequaltotype.h"
#include "../numeric/gcdvalue.h"

namespace crap
{
 template <class Type, char Sign1, char Sign2,
	  typename std :: make_unsigned <Type> :: type Numerator1, typename std :: make_unsigned <Type> :: type Denominator1,
	  typename std :: make_unsigned <Type> :: type Numerator2, typename std :: make_unsigned <Type> :: type Denominator2>
	struct notEqualToType<valueRatio<Type, Sign1, Numerator1, Denominator1>, valueRatio<Type, Sign2, Numerator2, Denominator2> >
{
 private:
  using valueType = typename std :: add_const <typename std :: make_unsigned <Type> :: type> :: type;
  constexpr static valueType gcd1 = gcdValue <typename std :: make_unsigned <Type> :: type, Numerator1, Denominator1> :: value;
  constexpr static valueType gcd2 = gcdValue <typename std :: make_unsigned <Type> :: type, Numerator2, Denominator2> :: value;
  constexpr static const bool numUnequal = ((Numerator1 / gcd1) != (Numerator2 / gcd2));
  constexpr static const bool denUnequal = ((Denominator1 / gcd1) != (Denominator2 / gcd2));
 public:
  constexpr static const bool value = (Sign1 != Sign2) || numUnequal || denUnequal;
};

 template <class Type1, char Sign1, typename std :: make_unsigned <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1,
	  class Type2, char Sign2, typename std :: make_unsigned <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
	 struct notEqualToType<valueRatio<Type1, Sign1, Numerator1, Denominator1>, valueRatio<Type2, Sign2, Numerator2, Denominator2>>
	 : notEqualToType<
		valueRatio<typename std :: common_type <Type1, Type2> :: type, Sign1,
		static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator1),
		static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator1)>,
		valueRatio<typename std :: common_type <Type1, Type2> :: type, Sign2,
		static_cast<typename std :: make_unsigned <typename std :: common_type<Type1, Type2> :: type> :: type>(Numerator2),
		static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator2)> >
	{};
}

template <class Type1, class Type2, char Sign1, char Sign2, typename std :: make_unsigned <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, typename std :: make_unsigned <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
inline constexpr bool operator != (crap :: valueRatio<Type1, Sign1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Sign2, Numerator2, Denominator2> ) noexcept
{
 return crap :: notEqualToType <crap :: valueRatio<Type1, Sign1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Sign2, Numerator2, Denominator2> > :: value;
}
#endif
