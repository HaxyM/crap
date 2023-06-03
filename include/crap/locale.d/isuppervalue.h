#ifndef CRAP_LOCALE_ISUPPERVALUE
#define CRAP_LOCALE_ISUPPERVALUE

#include "locale.h"

#include <type_traits>

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct isupperValue;

 template <class CharType, CharType Char> struct isupperValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool, (Char >= static_cast<CharType>(65)) && (Char <= static_cast<CharType>(90))>
	 {};
}
#endif

