#ifndef CRAP_LOCALE_ISGRAPHVALUE
#define CRAP_LOCALE_ISGRAPHVALUE

#include "locale.h"

#include <type_traits>

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct isgraphValue;

 template <class CharType, CharType Char> struct isgraphValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool, (Char >= static_cast<CharType>(33)) && (Char <= static_cast<CharType>(126))>
	 {};
}
#endif

