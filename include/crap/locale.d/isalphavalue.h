#ifndef CRAP_LOCALE_ISALPHAVALUE
#define CRAP_LOCALE_ISALPHAVALUE

#include "islowervalue.h"
#include "isuppervalue.h"
#include "locale.h"

#include <type_traits>

namespace crap
{
 template <class CharType, CharType, locale = locale :: C> struct isalphaValue;

 template <class CharType, CharType Char> struct isalphaValue<CharType, Char, locale :: C>
	 : std :: integral_constant<bool,
	 islowerValue <CharType, Char, locale :: C> :: value ||
	 isupperValue <CharType, Char, locale :: C> :: value>
	 {};
}
#endif

