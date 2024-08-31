#ifndef CRAP_ITERATOR_SSIZETYPE
#define CRAP_ITERATOR_SSIZETYPE

#include "ssizevalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class ... Types> struct ssizeType;

 template <class Type, Type ... Values> struct ssizeType<std :: integral_constant<Type, Values>...>
	 : typeIdentity<std :: integral_constant<decltype(ssizeValue <Type, Values...> :: value), ssizeValue <Type, Values...> :: value> >
	 {};

 template <class ... Type> using ssizeType_t = typename ssizeType <Type...> :: type;
}
#endif

