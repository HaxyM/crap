#ifndef CRAP_LOCALE_ISALNUMVALUE
#define CRAP_LOCALE_ISALNUMVALUE

#include "isalphavalue.h"
#include "isdigitvalue.h"
#include "locale.h"

#include <type_traits>

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct isalnumValue;

 template <class CharType, CharType Char> struct isalnumValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool,
	 isalphaValue <CharType, Char, locale :: C> :: value ||
	 isdigitValue <CharType, Char, locale :: C> :: value>
	 {};
}
#endif

