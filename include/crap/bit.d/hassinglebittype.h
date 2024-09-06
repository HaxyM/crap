#ifndef CRAP_BIT_HASSINGLEBITTYPE
#define CRAP_BIT_HASSINGLEBITTYPE

#include "hassinglebitvalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type> struct hasSingleBitType;

 template <class Type, Type Value> struct hasSingleBitType<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<decltype(hasSingleBitValue <Type, Value> :: value), hasSingleBitValue <Type, Value> :: value> >
	 {};

 template <class Type> using hasSingleBitType_t = typename hasSingleBitType <Type> :: type;
}
#endif

