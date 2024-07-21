#ifndef CRAP_UTILITY_INRANGEVALUE
#define CRAP_UTILITY_INRANGEVALUE

#include "language.h"
#if CPP20
#else
#include "cmpgreaterequalvalue.h"
#include "cmplessequalvalue.h"
#endif

#if CPP20
#include <utility>
#else
#include <limits>
#endif
#include <type_traits>

namespace crap
{
#if CPP20
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

