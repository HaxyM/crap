#ifndef CRAP_FUNCTIONAL_MULTIPLIESTYPE
#define CRAP_FUNCTIONAL_MULTIPLIESTYPE

#include "multipliesvalue.h"
#include "../numeric/reducetype.h"
#include "../utility/typeidentity.h"

#include <ratio>
#include <type_traits>

namespace crap
{
 template <class ... Types> struct multipliesType;

 template <class Type, Type ... Values> struct multipliesType<std :: integral_constant<Type, Values>...>
	 : typeIdentity<std :: integral_constant<decltype(multipliesValue <Type, Values...> :: value), multipliesValue <Type, Values...> :: value> >
	 {};
 template <intmax_t Numerator, intmax_t Denominator> struct multipliesType<std :: ratio<Numerator, Denominator> >
	 : typeIdentity<std :: ratio<Numerator, Denominator> > {};

 template <intmax_t Numerator1, intmax_t Denominator1, intmax_t Numerator2, intmax_t Denominator2>
	 struct multipliesType<std :: ratio<Numerator1, Denominator1>, std :: ratio<Numerator2, Denominator2> >
	 : typeIdentity<std :: ratio_multiply<std :: ratio<Numerator1, Denominator1>, std :: ratio<Numerator2, Denominator2> > >
	 {};
 template <intmax_t ... Numerators, intmax_t ... Denominators>
	 struct multipliesType<std :: ratio<Numerators, Denominators>...>
	 : reduceType<multipliesType, std :: ratio<Numerators, Denominators>...> {};
}
#endif

