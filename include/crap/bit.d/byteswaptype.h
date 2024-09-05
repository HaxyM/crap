#ifndef CRAP_BIT_BYTESWAPTYPE
#define CRAP_BIT_BYTESWAPTYPE

#include "byteswapvalue.h"
#include "../utility.d/typeidentity.h"

#include <type_traits>

namespace crap
{
 template <class Type> struct byteswapType;

 template <class Type, Type Value> struct byteswapType<std :: integral_constant<Type, Value> >
	 : typeIdentity<std :: integral_constant<decltype(byteswapValue <Type, Value> :: value), byteswapValue <Type, Value> :: value> >
	 {};

 template <class Type> using byteswapType_t = typename byteswapType <Type> :: type;
}
#endif

