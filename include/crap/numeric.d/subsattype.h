#ifndef CRAP_NUMERIC_SUBSATTYPE
#define CRAP_NUMERIC_SUBSATTYPE

#include "subsatvalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class ... Types> struct subSatType;

 template <class Type, Type ... Values> struct subSatType<std :: integral_constant<Type, Values>...>
	 : typeIdentity<std :: integral_constant<decltype(subSatValue <Type, Values...> :: value), subSatValue <Type, Values...> :: value> >
	 {};

 template <class ... Type> using subSatType_t = typename subSatType <Type...> :: type;
}
#endif

