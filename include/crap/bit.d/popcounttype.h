#ifndef CRAP_BIT_POPCOUNTTYPE
#define CRAP_BIT_POPCOUNTTYPE

#include "popcountvalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type> struct popcountType;

 template <class Type, Type Value> struct popcountType<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<decltype(popcountValue <Type, Value> :: value), popcountValue <Type, Value> :: value> >
	 {};

 template <class Type> using popcountType_t = typename popcountType <Type> :: type;
}
#endif

