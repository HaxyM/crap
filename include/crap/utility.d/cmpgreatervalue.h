#ifndef CRAP_UTILITY_CMPGREATERVALUE
#define CRAP_UTILITY_CMPGREATERVALUE

#include "../version.d/libintegercomparisonfunctions.h"
#if (crap_lib_integer_comparison_functions >= 202002L)
#else
#include "cmplessvalue.h"
#endif

#if (crap_lib_integer_comparison_functions >= 202002L)
#include <utility>
#else
#endif
#include <type_traits>

namespace crap
{
#if (crap_lib_integer_comparison_functions >= 202002L)
 template <class Type1, Type1 Value1, class Type2, Type2 Value2>
	 using cmpGreaterValue = std :: integral_constant<bool, std :: cmp_greater(Value1, Value2)>;
#else
 template <class Type1, Type1 Value1, class Type2, Type2 Value2>
	 using cmpGreaterValue = std :: integral_constant<bool,
	       (cmpLessValue <Type2, Value2, Type1, Value1> :: value)>;
#endif
}
#endif

