#ifndef CRAP_LOCALE_ISPUNCTVALUE
#define CRAP_LOCALE_ISPUNCTVALUE

#include "locale.h"

#include <type_traits>

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct ispunctValue;

 template <class CharType, CharType Char> struct ispunctValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool,
	 ((Char >= static_cast<CharType>(33)) && (Char <= static_cast<CharType>(47))) ||
	 ((Char >= static_cast<CharType>(58)) && (Char <= static_cast<CharType>(64))) ||
	 ((Char >= static_cast<CharType>(91)) && (Char <= static_cast<CharType>(96))) ||
	 ((Char >= static_cast<CharType>(123)) && (Char <= static_cast<CharType>(126)))>
	 {};
}
#endif

