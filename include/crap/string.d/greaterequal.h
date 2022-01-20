#ifndef CRAP_STRING_GREATEREQUAL
#define CRAP_STRING_GREATEREQUAL

#include "string.h"
#include "../algorithm.d/lexicographicalcomparefortype.h"
#include "../functional.d/greaterequaltype.h"

namespace crap
{
 template <class Type, Type ... Letters1, Type ... Letters2>
	 struct greaterEqualType<string<Type, Letters1...>, string<Type, Letters2...> >
	 : std :: integral_constant<bool, lexicographiclalCompareForType <Type> :: template type <Letters1...> :: template with <Letters2...> :: value !=
	 lexicographicalCompareForType <Type> :: detailedResult_t :: less> {};

 template <class Type, Type ... Letters1, Type ... Letters2> constexpr bool operator >= (string<Type, Letters1...>, string<Type, Letters2...>) noexcept;
}

template <class Type, Type ... Letters1, Type ... Letters2>
inline constexpr bool crap :: operator >= (crap :: string<Type, Letters1...>, crap :: string<Type, Letters2...>) noexcept
{
 return crap :: greaterEqualType <crap :: string<Type, Letters1...>, crap :: string<Type, Letters2...> > :: value;
}
#endif

