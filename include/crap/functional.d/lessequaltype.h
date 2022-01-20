#ifndef CRAP_FUNCTIONAL_LESSEQUALTYPE
#define CRAP_FUNCTIONAL_LESSEQUALTYPE

#include <ratio>
#include <type_traits>

namespace crap
{
 template <class Type1, class Type2> struct lessEqualType;

 template <class Type1, class Type2, Type1 Value1, Type2 Value2>
	 struct lessEqualType<std :: integral_constant<Type1, Value1>, std :: integral_constant<Type2, Value2> >
	 : std :: integral_constant<bool, (Value1 <= Value2)> {};
 template <intmax_t Numerator1, intmax_t Denominator1, intmax_t Numerator2, intmax_t Denominator2>
	 struct lessEqualType<std :: ratio<Numerator1, Denominator1>, std :: ratio<Numerator2, Denominator2> >
	 : std :: ratio_less_equal<std :: ratio<Numerator1, Denominator1>, std :: ratio<Numerator2, Denominator2> >
	 {};
}
#endif

