#ifndef CRAP_BIT_COUNTRZEROTYPE
#define CRAP_BIT_COUNTRZEROTYPE

#include "countrzerovalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type> struct countrZeroType;

 template <class Type, Type Value> struct countrZeroType<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<decltype(countrZeroValue <Type, Value> :: value), countrZeroValue <Type, Value> :: value> >
	 {};

 template <class Type> using countrZeroType_t = typename countrZeroType <Type> :: type;
}
#endif

