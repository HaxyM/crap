#ifndef CRAP_LOCALE_ISCNTRLVALUE
#define CRAP_LOCALE_ISCNTRLVALUE

#include "locale.h"

#include <type_traits>

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct iscntrlValue;

 template <class CharType, CharType Char> struct iscntrlValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool,
	 ((Char >= static_cast<CharType>(0)) && (Char <= static_cast<CharType>(31))) ||
	 (Char == static_cast<CharType>(127))>
	 {};
}
#endif

