#ifndef CRAP_UTILITY_CMPNOTEQUALVALUE
#define CRAP_UTILITY_CMPNOTEQUALVALUE

#include "../version.d/libintegercomparisonfunctions.h"
#if (crap_lib_integer_comparison_functions >= 202002L)
#else
#include "cmpequalvalue.h"
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
	 using cmpNotEqualValue = std :: integral_constant<bool, std :: cmp_not_equal(Value1, Value2)>;
#else
 template <class Type1, Type1 Value1, class Type2, Type2 Value2>
	 using cmpNotEqualValue = std :: integral_constant<bool,
	       !(cmpEqualValue <Type1, Value1, Type2, Value2> :: value)>;
#endif
}
#endif

