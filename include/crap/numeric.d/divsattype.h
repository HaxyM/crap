#ifndef CRAP_NUMERIC_DIVSATTYPE
#define CRAP_NUMERIC_DIVSATTYPE

#include "divsatvalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class ... Types> struct divSatType;

 template <class Type, Type ... Values> struct divSatType<std :: integral_constant<Type, Values>...>
	 : typeIdentity<std :: integral_constant<decltype(divSatValue <Type, Values...> :: value), divSatValue <Type, Values...> :: value> >
	 {};

 template <class ... Type> using divSatType_t = typename divSatType <Type...> :: type;
}
#endif

