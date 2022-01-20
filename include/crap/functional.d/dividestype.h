#ifndef CRAP_FUNCTIONAL_DIVIDESTYPE
#define CRAP_FUNCTIONAL_DIVIDESTYPE

#include "dividesvalue.h"
#include "../numeric.d/reducetype.h"
#include "../utility.d/typeidentity.h"

#include <ratio>
#include <type_traits>

namespace crap
{
 template <class ... Types> struct dividesType;

 template <class Type, Type ... Values> struct dividesType<std :: integral_constant<Type, Values>...>
	 : typeIdentity<std :: integral_constant<decltype(dividesValue <Type, Values...> :: value), dividesValue <Type, Values...> :: value> >
	 {};
 template <intmax_t Numerator, intmax_t Denominator> struct dividesType<std :: ratio<Numerator, Denominator> >
	 : typeIdentity<std :: ratio<Numerator, Denominator> > {};

 template <intmax_t Numerator1, intmax_t Denominator1, intmax_t Numerator2, intmax_t Denominator2>
	 struct dividesType<std :: ratio<Numerator1, Denominator1>, std :: ratio<Numerator2, Denominator2> >
	 : typeIdentity<std :: ratio_divide<std :: ratio<Numerator1, Denominator1>, std :: ratio<Numerator2, Denominator2> > >
	 {};
 template <intmax_t ... Numerators, intmax_t ... Denominators>
	 struct dividesType<std :: ratio<Numerators, Denominators>...>
	 : reduceType<dividesType, std :: ratio<Numerators, Denominators>...> {};
}
#endif

