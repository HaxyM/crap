#ifndef CRAP_LOCALE_ISLOWERVALUE
#define CRAP_LOCALE_ISLOWERVALUE

#include "locale.h"

#include <type_traits>

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct islowerValue;

 template <class CharType, CharType Char> struct islowerValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool, (Char >= static_cast<CharType>(97)) && (Char <= static_cast<CharType>(122))>
	 {};
}
#endif

