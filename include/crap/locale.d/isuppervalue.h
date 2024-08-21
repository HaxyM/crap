#ifndef CRAP_LOCALE_ISUPPERVALUE
#define CRAP_LOCALE_ISUPPERVALUE

#include <cstdint>
#include <type_traits>

#include "locale.h"
#include "../utility.d/cmpgreaterequalvalue.h"
#include "../utility.d/cmplessequalvalue.h"

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct isupperValue;

 template <class CharType, CharType Char> struct isupperValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool, (cmpGreaterEqualValue <CharType, Char, std :: uint32_t, UINT32_C(65)> :: value)
	 && (cmpLessEqualValue <CharType, Char, std :: uint32_t, UINT32_C(90)> :: value)>
	 {};
}
#endif

