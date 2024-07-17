#ifndef CRAP_UTILITY_CMPEQUALVALUE
#define CRAP_UTILITY_CMPEQUALVALUE

#include "language.h"
#if CPP20
#else
#include "../numbers.d/zero.h"
#endif

#if CPP20
#include <utility>
#else
#endif
#include <type_traits>

namespace crap
{
#if CPP20
 template <class Type1, Type1 Value1, class Type2, Type2 Value2>
	 using cmpEqualValue = std :: integral_constant<bool, std :: cmp_equal(Value1, Value2)>;
#else
 template <class Type1, Type1 Value1, class Type2, Type2 Value2>
	 using cmpEqualValue = std :: integral_constant<bool,
	       ((std :: is_signed <Type1> :: value == std :: is_signed <Type2> :: value)
		? (Value1 == Value2)
		: ((std :: is_signed <Type1> :: value)
			? ((Value1 >= zero <Type1> :: value)
				? (static_cast<typename std :: make_unsigned <Type1> :: type>(Value1) == Value2)
				: false)
			: ((Value2 >= zero <Type2> :: value)
				? (Value1 == static_cast<typename std :: make_unsigned <Type2> :: type>(Value2))
				: false)))>;
#endif
}
#endif

