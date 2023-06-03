#ifndef CRAP_LOCALE_ISXDIGITVALUE
#define CRAP_LOCALE_ISXDIGITVALUE

#include "isdigitvalue.h"
#include "locale.h"

#include <type_traits>

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct isxdigitValue;

 template <class CharType, CharType Char> struct isxdigitValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool,
	 isdigitValue <CharType, Char, locale :: C> :: value ||
	 ((Char >= static_cast<CharType>(65)) && (Char <= static_cast<CharType>(70))) ||
	 ((Char >= static_cast<CharType>(97)) && (Char <= static_cast<CharType>(102)))>
	 {};
}
#endif

