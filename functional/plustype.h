#ifndef CRAP_FUNCTIONAL_PLUSTYPE
#define CRAP_FUNCTIONAL_PLUSTYPE

#include "plusvalue.h"
#include "../numeric/reducetype.h"
#include "../utility/typeidentity.h"

#include <ratio>
#include <type_traits>

namespace crap
{
 template <class ... Types> struct plusType;

 template <class Type, Type ... Values> struct plusType<std :: integral_constant<Type,Values>...>
	 : typeIdentity<std :: integral_constant<decltype(plusValue <Type, Values...> :: value), plusValue <Type, Values...> :: value> >
	 {};

 template <intmax_t Numerator, intmax_t Denominator> struct plusType<std :: ratio<Numerator, Denominator> >
	 : typeIdentity<std :: ratio<Numerator, Denominator> > {};

 template <intmax_t Numerator1, intmax_t Denominator1, intmax_t Numerator2, intmax_t Denominator2>
	 struct plusType<std :: ratio<Numerator1, Denominator1>, std :: ratio<Numerator2, Denominator2> >
	 : typeIdentity<std :: ratio_add<std :: ratio<Numerator1, Denominator1>, std :: ratio<Numerator2, Denominator2> > >
	 {};
 template <intmax_t ... Numerators, intmax_t ... Denominators>
	 struct plusType<std :: ratio<Numerators, Denominators>...>
	 : reduceType<plusType, std :: ratio<Numerators, Denominators>...> {};
}
#endif

