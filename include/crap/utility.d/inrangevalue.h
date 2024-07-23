#ifndef CRAP_UTILITY_INRANGEVALUE
#define CRAP_UTILITY_INRANGEVALUE

#include "../version.d/libintegercomparisonfunctions.h"
#if (crap_lib_integer_comparison_functions >= 202002L)
#else
#include "cmpgreaterequalvalue.h"
#include "cmplessequalvalue.h"
#endif

#if (crap_lib_integer_comparison_functions >= 202002L)
#include <utility>
#else
#include <limits>
#endif
#include <type_traits>

namespace crap
{
#if (crap_lib_integer_comparison_functions >= 202002L)
 template <class TypeToFitIn, class Type, Type Value>
	 using inRangeValue = std :: integral_constant<bool,
	       std :: in_range<TypeToFitIn>(Value)>;
#else
 template <class TypeToFitIn, class Type, Type Value>
	 using inRangeValue = std :: integral_constant<bool,
	       (cmpGreaterEqualValue <Type, Value, TypeToFitIn, std :: numeric_limits <TypeToFitIn> :: min()> :: value
		&& cmpLessEqualValue <Type, Value, TypeToFitIn, std :: numeric_limits <TypeToFitIn> :: max()> :: value)>;
#endif
}
#endif

