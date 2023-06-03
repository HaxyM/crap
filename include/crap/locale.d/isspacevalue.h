#ifndef CRAP_LOCALE_ISSPACEVALUE
#define CRAP_LOCALE_ISSPACEVALUE

#include "isblankvalue.h"
#include "locale.h"

#include <type_traits>

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct isspaceValue;

 template <class CharType, CharType Char> struct isspaceValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool,
	 isblankValue <CharType, Char, locale :: C> :: value ||
	 ((Char >= static_cast<CharType>(10)) && (Char <= static_cast<CharType>(13)))>
	 {};
}
#endif

