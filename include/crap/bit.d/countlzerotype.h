#ifndef CRAP_BIT_COUNTLZEROTYPE
#define CRAP_BIT_COUNTLZEROTYPE

#include "countlzerovalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type> struct countlZeroType;

 template <class Type, Type Value> struct countlZeroType<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<decltype(countlZeroValue <Type, Value> :: value), countlZeroValue <Type, Value> :: value> >
	 {};

 template <class Type> using countlZeroType_t = typename countlZeroType <Type> :: type;
}
#endif

