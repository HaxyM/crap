#ifndef CRAP_NUMERIC_ADDSATTYPE
#define CRAP_NUMERIC_ADDSATTYPE

#include "addsatvalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class ... Types> struct addSatType;

 template <class Type, Type ... Values> struct addSatType<std :: integral_constant<Type, Values>...>
	 : typeIdentity<std :: integral_constant<decltype(addSatValue <Type, Values...> :: value), addSatValue <Type, Values...> :: value> >
	 {};

 template <class ... Type> using addSatType_t = typename addSatType <Type...> :: type;
}
#endif

