#ifndef CRAP_LOCALE_ISDIGITVALUE
#define CRAP_LOCALE_ISDIGITVALUE

#include "locale.h"

#include <type_traits>

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct isdigitValue;

 template <class CharType, CharType Char> struct isdigitValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool, (Char >= static_cast<CharType>(48)) && (Char <= static_cast<CharType>(57))>
	 {};
}
#endif

