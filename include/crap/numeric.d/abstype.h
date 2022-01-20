#ifndef CRAP_NUMERIC_ABSTYPE
#define CRAP_NUMERIC_ABSTYPE

#include <ratio>
#include <type_traits>

#include "absvalue.h"
#include "../utility.d/typeidentity.h"

namespace crap
{
 template <class Type> struct absType;

 template <class Type, Type Value> struct absType<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<typename absValue <Type, Value> :: value_type, absValue <Type, Value> :: value> >
 {};

 template <intmax_t Numerator, intmax_t Denominator> struct absType<std :: ratio<Numerator, Denominator> >
	 : typeIdentity<std :: ratio<absValue <intmax_t, Numerator> :: value, absValue <intmax_t, Denominator> :: value> >
 {};
}
#endif

