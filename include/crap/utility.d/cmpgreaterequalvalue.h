#ifndef CRAP_UTILITY_CMPGREATEREQUALVALUE
#define CRAP_UTILITY_CMPGREATEREQUALVALUE

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
	 using cmpGreaterEqualValue = std :: integral_constant<bool,
	       std :: cmp_greater_equal(Value1, Value2)>;
#else
 template <class Type1, Type1 Value1, class Type2, Type2 Value2>
	 using cmpGreaterEqualValue = std :: integral_constant<bool,
	       !(cmpLessValue <Type1, Value1, Type2, Value2> :: value)>;
#endif
}
#endif

