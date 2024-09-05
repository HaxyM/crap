#ifndef CRAP_BIT_BITCEILTYPE
#define CRAP_BIT_BITCEILTYPE

#include "bitceilvalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type> struct bitCeilType;

 template <class Type, Type Value> struct bitCeilType<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<decltype(bitCeilValue <Type, Value> :: value), bitCeilValue <Type, Value> :: value> >
	 {};

 template <class Type> using bitCeilType_t = typename bitCeilType <Type> :: type;
}
#endif

