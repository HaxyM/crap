#ifndef CRAP_NUMERIC_GCDTYPE
#define CRAP_NUMERIC_GCDTYPE

#include "gcdvalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class ... Types> struct gcdType;

 template <class Type, Type ... Values> struct gcdType<std :: integral_constant<Type, Values>...>
	 : typeIdentity<std :: integral_constant<decltype(gcdValue <Type, Values...> :: value), gcdValue <Type, Values...> :: value> >
	 {};

 template <class ... Type> using gcdType_t = typename gcdType <Type...> :: type;
}
#endif

