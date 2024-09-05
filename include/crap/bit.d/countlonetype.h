#ifndef CRAP_BIT_COUNTLONETYPE
#define CRAP_BIT_COUNTLONETYPE

#include "countlonevalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type> struct countlOneType;

 template <class Type, Type Value> struct countlOneType<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<decltype(countlOneValue <Type, Value> :: value), countlOneValue <Type, Value> :: value> >
	 {};

 template <class Type> using countlOneType_t = typename countlOneType <Type> :: type;
}
#endif

