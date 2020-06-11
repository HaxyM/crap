#ifndef CRAP_STRING_LESS
#define CRAP_STRING_LESS

#include "string.h"
#include "../algorithm/lexicographicalcomparevalue.h"
#include "../functional/comparatorsfortype.h"
#include "../functional/lesstype.h"

namespace crap
{
 template <class Type, Type ... Letters1, Type ... Letters2>
	 struct lessType<string<Type, Letters1...>, string<Type, Letters2...> >
	 : lexicographicalCompareValue <Type, comparatorsForType <Type> :: template Less, Letters1...> :: template
	 with <Letters2...> {};

 template <class Type, Type ... Letters1, Type ... Letters2> constexpr bool operator < (string<Type, Letters1...>, string<Type, Letters2...>) noexcept;
}

template <class Type, Type ... Letters1, Type ... Letters2>
inline constexpr bool crap :: operator < (crap :: string<Type, Letters1...>, crap :: string<Type, Letters2...>) noexcept
{
 return crap :: lessType <crap :: string<Type, Letters1...>, crap :: string<Type, Letters2...> > :: value;
}
#endif

