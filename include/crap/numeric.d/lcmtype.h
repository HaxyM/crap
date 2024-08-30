#ifndef CRAP_NUMERIC_LCMTYPE
#define CRAP_NUMERIC_LCMTYPE

#include "lcmvalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class ... Types> struct lcmType;

 template <class Type, Type ... Values> struct lcmType<std :: integral_constant<Type, Values>...>
	 : typeIdentity<std :: integral_constant<decltype(lcmValue <Type, Values...> :: value), lcmValue <Type, Values...> :: value> >
	 {};

 template <class ... Type> using lcmType_t = typename lcmType <Type...> :: type;
}
#endif

