#ifndef CRAP_NUMERIC_MULSATTYPE
#define CRAP_NUMERIC_MULSATTYPE

#include "mulsatvalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class ... Types> struct mulSatType;

 template <class Type, Type ... Values> struct mulSatType<std :: integral_constant<Type, Values>...>
	 : typeIdentity<std :: integral_constant<decltype(mulSatValue <Type, Values...> :: value), mulSatValue <Type, Values...> :: value> >
	 {};

 template <class ... Type> using mulSatType_t = typename mulSatType <Type...> :: type;
}
#endif

