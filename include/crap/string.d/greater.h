#ifndef CRAP_STRING_GREATER
#define CRAP_STRING_GREATER

#include "string.h"
#include "../algorithm.d/lexicographicalcomparefortype.h"
#include "../functional.d/greatertype.h"

namespace crap
{
 template <class Type, Type ... Letters1, Type ... Letters2>
	 struct greaterType<string<Type, Letters1...>, string<Type, Letters2...> >
	 : std :: integral_constant<bool, lexicographiclalCompareForType <Type> :: template type <Letters1...> :: template with <Letters2...> :: value ==
	 lexicographicalCompareForType <Type> :: detailedResult_t :: greater> {};

 template <class Type, Type ... Letters1, Type ... Letters2> constexpr bool operator > (string<Type, Letters1...>, string<Type, Letters2...>) noexcept;
}

template <class Type, Type ... Letters1, Type ... Letters2>
inline constexpr bool crap :: operator > (crap :: string<Type, Letters1...>, crap :: string<Type, Letters2...>) noexcept
{
 return crap :: greaterType <crap :: string<Type, Letters1...>, crap :: string<Type, Letters2...> > :: value;
}
#endif

