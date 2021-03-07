#ifndef CRAP_RATIO_NOTEQUALTOTYPE
#define CRAP_RATIO_NOTEQUALTOTYPE

#include <type_traits>

#include "contracttype.h"
#include "valueratio.h"
#include "../functional/notequaltotype.h"

namespace crap
{
 template <class Type,
	  typename std :: make_signed <Type> :: type Numerator1, typename std :: make_unsigned <Type> :: type Denomiantor1,
	  typename std :: make_signed <Type> :: type Numerator2, typename std :: make_unsigned <Type> :: type Denominator2>
	 struct notEqualToType<valueRatio<Type, Numerator1, Denominator1>, valueRatio<Type, Numerator2, Denominator2> >
	 : std :: integral_constant<bool,
		(contractType <valueRatio<Type, Numerator1, Denominator1> > :: type :: num != contractType <valueRatio<Type, Numerator2, Denominator2> > :: type :: num)
		 || (contractType <valueRatio<Type, Numerator1, Denominator1> > :: type :: den != contractType <valueRatio<Type, Numerator2, Denominator2> > :: type :: den)>
	{};

 template <class Type1, typename std :: make_signed <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1,
	  class Type2, typename std :: make_signed <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
	 struct notEqualToType<valueRatio<Type1, Numerator1, Denominator1>, valueRatio<Type2, Numerator2, Denominator2>>
	 : notEqualToType<
		valueRatio<typename std :: common_type <Type1, Type2> :: type,
		static_cast<typename std :: make_signed <typename std :: common_type <Type1, Type2> :: type> :: type>(Numerator1),
		static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator1)>,
		valueRatio<typename std :: common_type <Type1, Type2> :: type,
		static_cast<typename std :: make_signed <typename std :: common_type<Type1, Type2> :: type> :: type>(Numerator2),
		static_cast<typename std :: make_unsigned <typename std :: common_type <Type1, Type2> :: type> :: type>(Denominator2)> >
	{};
}

template <class Type1, class Type2, typename std :: make_signed <Type1> :: type Numerator1, typename std :: make_unsigned <Type1> :: type Denominator1, typename std :: make_signed <Type2> :: type Numerator2, typename std :: make_unsigned <Type2> :: type Denominator2>
inline constexpr bool operator != (crap :: valueRatio<Type1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Numerator2, Denominator2> ) noexcept
{
 return crap :: notEqualToType <crap :: valueRatio<Type1, Numerator1, Denominator1>, crap :: valueRatio<Type2, Numerator2, Denominator2> > :: value;
}
#endif

