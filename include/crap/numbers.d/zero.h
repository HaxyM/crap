#ifndef CRAP_NUMERIC_ZERO
#define CRAP_NUMERIC_ZERO

#include <ratio>
#include <type_traits>

#include "../numbers.d/identity.h"
#include "../utility.d/typeidentity.h"

namespace crap
{
 template <class Type> struct zero : std :: integral_constant<Type, static_cast<Type>(0)>{};

 template <class Type, Type Value> struct zero<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<typename zero <Type> :: value_type, zero <Type> :: value> >
 {};

 template <intmax_t Numerator, intmax_t Denominator> struct zero<std :: ratio<Numerator, Denominator> >
	 : typeIdentity<std :: ratio<zero <intmax_t> :: value, identity <intmax_t> :: value> >
 {};
}
#endif

