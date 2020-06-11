#ifndef CRAP_FUNCTIONAL_NOTEQUALTOTYPE
#define CRAP_FUNCTIONAL_NOTEQUALTOTYPE

#include <type_traits>

namespace crap
{
 template <class Type1, class Type2> struct notEqualToType : std :: integral_constant<bool, std :: is_same<Type1, Type2> :: value> {};

 template <class Type1, class Type2, Type1 Value1, Type2 Value2>
	 struct notEqualToType<std :: integral_constant<Type1, Value1>, std :: integral_constant<Type2, Value2> >
	 : std :: integral_constant<bool, (Value1 != Value2)> {};
}
#endif

