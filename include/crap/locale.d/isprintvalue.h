#ifndef CRAP_LOCALE_ISPRINTVALUE
#define CRAP_LOCALE_ISPRINTVALUE

#include "locale.h"

#include <type_traits>

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct isprintValue;

 template <class CharType, CharType Char> struct isprintValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool, (Char >= static_cast<CharType>(32)) && (Char <= static_cast<CharType>(126))>
	 {};
}
#endif

