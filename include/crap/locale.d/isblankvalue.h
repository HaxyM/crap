#ifndef CRAP_LOCALE_ISBLANKVALUE
#define CRAP_LOCALE_ISBLANKVALUE

#include "locale.h"

#include <type_traits>

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct isblankValue;

 template <class CharType, CharType Char> struct isblankValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool, (Char == static_cast<CharType>(9)) || (Char == static_cast<CharType>(32))>
	 {};
}
#endif

