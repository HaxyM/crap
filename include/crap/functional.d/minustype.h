#ifndef CRAP_FUNCTIONAL_MINUSTYPE
#define CRAP_FUNCTIONAL_MINUSTYPE

#include "minusvalue.h"
#include "../numeric.d/reducetype.h"
#include "../utility.d/typeidentity.h"

#include <ratio>
#include <type_traits>

namespace crap
{
 template <class ... Types> struct minusType;

 template <class Type, Type ... Values> struct minusType<std :: integral_constant<Type,Values>...>
	 : typeIdentity<std :: integral_constant<decltype(minusValue <Type, Values...> :: value), minusValue <Type, Values...> :: value> >
	 {};

 template <intmax_t Numerator, intmax_t Denominator> struct minusType<std :: ratio<Numerator, Denominator> >
	 : typeIdentity<std :: ratio<Numerator, Denominator> > {};

 template <intmax_t Numerator1, intmax_t Denominator1, intmax_t Numerator2, intmax_t Denominator2>
	 struct minusType<std :: ratio<Numerator1, Denominator1>, std :: ratio<Numerator2, Denominator2> >
	 : typeIdentity<std :: ratio_subtract<std :: ratio<Numerator1, Denominator1>, std :: ratio<Numerator2, Denominator2> > >
	 {};
 template <intmax_t ... Numerators, intmax_t ... Denominators>
	 struct minusType<std :: ratio<Numerators, Denominators>...>
	 : reduceType<minusType, std :: ratio<Numerators, Denominators>...> {};
}
#endif

