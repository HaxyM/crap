#ifndef CRAP_FUNCTIONAL_NEGATETYPE
#define CRAP_FUNCTIONAL_NEGATETYPE

#include "negatevalue.h"
#include "../utility/typeidentity.h"

#include <ratio>
#include <type_traits>

namespace crap
{
 template <class> struct negateType;

 template <class Type, Type Value> struct negateType<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<typename negateValue <Type, Value> :: value_type, negateValue <Type, Value> :: value> >
 {};

 template <intmax_t Numerator, intmax_t Denominator> struct negateType<std :: ratio<Numerator, Denominator> >
	 : typeIdentity<std :: ratio_subtract<std :: ratio<0>, std :: ratio<Numerator, Denominator> > > {};
}
#endif

