#ifndef CRAP_BIT_BITWIDTHTYPE
#define CRAP_BIT_BITWIDTHTYPE

#include "bitwidthvalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type> struct bitWidthType;

 template <class Type, Type Value> struct bitWidthType<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<decltype(bitWidthValue <Type, Value> :: value), bitWidthValue <Type, Value> :: value> >
	 {};

 template <class Type> using bitWidthType_t = typename bitWidthType <Type> :: type;
}
#endif

