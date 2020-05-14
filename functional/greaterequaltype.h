#ifndef CRAP_FUNCTIONAL_GREATEREQUALTYPE
#define CRAP_FUNCTIONAL_GREATEREQUALTYPE

#include <type_traits>

namespace crap
{
 template <class Type1, class Type2> struct greaterEqualType;

 template <class Type1, class Type2, Type1 Value1, Type2 Value2>
	 struct greaterEqualType<std :: integral_constant<Type1, Value1>, std :: integral_constant<Type2, Value2> >
	 : std :: integral_constant<bool, (Value1 >= Value2)> {};
}
#endif
