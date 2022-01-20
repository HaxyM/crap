#ifndef CRAP_NUMERIC_IDENTITY
#define CRAP_NUMERIC_IDENTITY

#include <ratio>
#include <type_traits>

#include "../utility.d/typeidentity.h"

namespace crap
{
 template <class Type> struct identity : std :: integral_constant<Type, static_cast<Type>(1)>{};

 template <class Type, Type Value> struct identity<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<typename identity <Type> :: value_type, identity <Type> :: value> >
 {};

 template <intmax_t Numerator, intmax_t Denominator> struct identity<std :: ratio<Numerator, Denominator> >
	 : typeIdentity<std :: ratio<identity <intmax_t> :: value, identity <intmax_t> :: value> >
 {};
}
#endif

