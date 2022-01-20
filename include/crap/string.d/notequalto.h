#ifndef CRAP_STRING_NOTEQUALTO
#define CRAP_STRING_NOTEQUALTO

#include "string.h"
#include "../algorithm.d/lexicographicalcomparevalue.h"
#include "../functional.d/comparatorsfortype.h"
#include "../functional.d/notequaltotype.h"

namespace crap
{
 template <class Type, Type ... Letters1, Type ... Letters2>
	 struct notEqualToType<string<Type, Letters1...>, string<Type, Letters2...> >
	 : std :: integral_constant<bool, lexicographiclalCompareForType <Type> :: template type <Letters1...> :: template with <Letters2...> :: value !=
	 lexicographicalCompareForType <Type> :: detailedResult_t :: equal> {};

 template <class Type, Type ... Letters1, Type ... Letters2> constexpr bool operator != (string<Type, Letters1...>, string<Type, Letters2...>) noexcept;
}

template <class Type, Type ... Letters1, Type ... Letters2>
inline constexpr bool crap :: operator != (crap :: string<Type, Letters1...>, crap :: string<Type, Letters2...>) noexcept
{
 return crap :: notEqualToType <crap :: string<Type, Letters1...>, crap :: string<Type, Letters2...> > :: value;
}
#endif

