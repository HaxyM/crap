#ifndef CRAP_UTILITY_CMPLESSEQUALVALUE
#define CRAP_UTILITY_CMPLESSEQUALVALUE

#include "language.h"
#if CPP20
#else
#include "cmplessvalue.h"
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
	 using cmpLessEqualValue = std :: integral_constant<bool, std :: cmp_less_equal(Value1, Value2)>;
#else
 template <class Type1, Type1 Value1, class Type2, Type2 Value2>
	 using cmpLessEqialValue = std :: integral_constant<bool,
	       !(cmpLessValue <Type2, Value2, Type1, Value1> :: value)>;
#endif
}
#endif

