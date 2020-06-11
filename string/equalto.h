#ifndef CRAP_STRING_EQUALTO
#define CRAP_STRING_EQUALTO

#include "string.h"
#include "../algorithm/equalvalue.h"
#include "../functional/comparatorsfortype.h"
#include "../functional/equaltotype.h"

namespace crap
{
 template <class Type, Type ... Letters1, Type ... Letters2>
	 struct equalToType<string<Type, Letters1...>, string<Type, Letters2...> >
	 : equalValue <Type, comparatorsForType <Type> :: template EqualTo, Letters1...> :: template
	 with <Letters2...> {};

 template <class Type, Type ... Letters1, Type ... Letters2> constexpr bool operator == (string<Type, Letters1...>, string<Type, Letters2...>) noexcept;
}

template <class Type, Type ... Letters1, Type ... Letters2>
inline constexpr bool crap :: operator == (crap :: string<Type, Letters1...>, crap :: string<Type, Letters2...>) noexcept
{
 return crap :: equalToType <crap :: string<Type, Letters1...>, crap :: string<Type, Letters2...> > :: value;
}
#endif

