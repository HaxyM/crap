#ifndef CRAP_BIT_BITFLOORTYPE
#define CRAP_BIT_BITFLOORTYPE

#include "bitfloorvalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type> struct bitFloorType;

 template <class Type, Type Value> struct bitFloorType<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<decltype(bitFloorValue <Type, Value> :: value), bitFloorValue <Type, Value> :: value> >
	 {};

 template <class Type> using bitFloorType_t = typename bitFloorType <Type> :: type;
}
#endif

