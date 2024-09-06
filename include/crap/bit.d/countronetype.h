#ifndef CRAP_BIT_COUNTRONETYPE
#define CRAP_BIT_COUNTRONETYPE

#include "countronevalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type> struct countrOneType;

 template <class Type, Type Value> struct countrOneType<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<decltype(countrOneValue <Type, Value> :: value), countrOneValue <Type, Value> :: value> >
	 {};

 template <class Type> using countrOneType_t = typename countrOneType <Type> :: type;
}
#endif

