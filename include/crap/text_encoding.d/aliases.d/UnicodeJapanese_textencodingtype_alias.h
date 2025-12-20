#include <type_traits>

#include "../IANA_encodings.d/UnicodeJapanese_textencodingtype.h"
#include "../textencodingtype.h"

#ifndef CRAP_TEXTENCODING_ALIASES_UNICODEJAPANESETEXTENCODINGTYPEALIAS
#define CRAP_TEXTENCODING_ALIASES_UNICODEJAPANESETEXTENCODINGTYPEALIAS

namespace crap
{
 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'c', 's', 'u', 'n', 'i', 'c', 'o', 'd', 'e', 'j', 'a', 'p', 'a', 'n', 'e', 's', 'e'>
 : textEncodingType<text_encoding_id_UnicodeJapanese_t>
 {
 };

 template <class CharType, CharType ... Letters>
	 template <class PlaceHolder>
 struct textEncodingType<string<CharType, Letters...> > ::
 alias<PlaceHolder, char, 'i', 's', 'o', '1', '0', '6', '4', '6', 'j', '1'>
 : textEncodingType<text_encoding_id_UnicodeJapanese_t>
 {
 };
}
#endif
